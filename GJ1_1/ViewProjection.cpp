#include "ViewProjection.h"
#include "DxLib.h"

ViewProjection::ViewProjection(const Vector2& pos, const Vector2& upl, const Vector2& lor)
	:pos(pos), upl(upl), lor(lor)
{
}

void ViewProjection::DrawGraph(const GraphDeta& graph)
{
	Vector2 localPos = graph.pos - this->pos;
	Vector2 graphSize = graph.GetGraphSize();

	unsigned brightRed = graph.bright & 0xFF0000;
	unsigned brightGreen = graph.bright & 0x00FF00;
	unsigned brightBlue = graph.bright & 0x0000FF;

	DxLib::SetDrawArea(upl.x, upl.y, lor.x, lor.y);
	DxLib::SetDrawBlendMode(graph.blendMode, graph.blendPal);
	DxLib::SetDrawBright(brightRed, brightGreen, brightBlue);

	DxLib::DrawRotaGraph3(localPos.x, localPos.y, graphSize.x / 2.f, graphSize.y / 2.f,
		graph.extRate.x, graph.extRate.y, graph.angle, graph.grHandle,
		true, 0, 0);

	DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DxLib::SetDrawBright(255, 255, 255);
}
