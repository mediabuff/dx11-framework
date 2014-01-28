// Copyright (c) 2011-2014, Stoyan Nikolov
// All rights reserved.
// This software is governed by a permissive BSD-style license. See LICENSE.
#pragma once

#include "TexturePtr.h"

enum MaterialProperties
{
	MP_Diffuse = 1,
	MP_Normal = 2,
	MP_AlphaMask = 4,
	MP_SpecularMap = 8,
	MP_SpecularPower = 16,
};

class Material
{
public:
	Material();

	const DirectX::XMFLOAT3& GetDiffuseColor() const;
	void SetDiffuseColor(const DirectX::XMFLOAT3&);

	TexturePtr GetDiffuse() const;
	void SetDiffuse(const TexturePtr&);

	TexturePtr GetNormalMap() const;
	void SetNormalMap(const TexturePtr&);

	TexturePtr GetAlphaMask() const;
	void SetAlphaMask(const TexturePtr&);

	TexturePtr GetSpecularMap() const;
	void SetSpecularMap(const TexturePtr&);

	float GetSpecularPower() const;
	void SetSpecularPower(float power);

	bool HasProperty(MaterialProperties prop) const;

	unsigned GetProperties() const
	{
		return m_Properties;
	}

private:
	unsigned m_Properties;
	
	TexturePtr m_Diffuse;
	TexturePtr m_NormalMap;
	TexturePtr m_AlphaMask;
	TexturePtr m_SpecularMap;
	DirectX::XMFLOAT3 m_DiffuseColor;
	float m_SpecularPower;
};