#include "Renderer.h"

Renderer::Renderer(Window& window) {
	createDevice(window);
	createRenderTarget();
}

void Renderer::createDevice(Window& window) {
	//Define swap chain
	DXGI_SWAP_CHAIN_DESC swapChainDesc = {0};
	
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.Get_Handle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	auto result = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&swapChainDesc,
		&m_SwapChain,
		&m_Device,
		nullptr,
		&m_DeviceContext);

	if (result != S_OK) {
		MessageBox(nullptr, "Error DX11", "Error", MB_OK);
		exit(0);
	}
}

void Renderer::createRenderTarget() {
	ID3D11Texture2D* backBuffer;
	m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**) &backBuffer);
	m_Device->CreateRenderTargetView(backBuffer, nullptr, &m_renderTargetView);
	backBuffer->Release();
}

void Renderer::beginFrame() {
	// Set the background color
	float randColor = float(rand() % 255) / 255.f;
	float nonclearColor[] = { randColor, .5f, 1, 1 };
	float clearColor[] = { .25f, .5f, 1, 1 }; 
		m_DeviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);
}

void Renderer::endFrame() {
	// Swap the buffer
	m_SwapChain->Present(1,0);
}