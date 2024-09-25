#pragma once
#include "Window.h"
#include <d3d11.h>

class Renderer
{
public:
	Renderer(Window &window);
	void beginFrame();
	void endFrame();

private:
	void createDevice(Window& window);
	void createRenderTarget();

	// Device
	IDXGISwapChain* m_SwapChain = nullptr;
	ID3D11Device* m_Device = nullptr;
	ID3D11DeviceContext* m_DeviceContext = nullptr;

	// Render target
	ID3D11RenderTargetView* m_renderTargetView = nullptr;

};
