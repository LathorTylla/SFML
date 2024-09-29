#pragma once
class Window;

enum
ComponentType{
	NONE = 0,
  TRANSFORM = 1,
	SPRITE =2,
	RENDERER= 3,
	PHYSICS=4
};

class 
Component
{
public:
	Component() = default;

	Component(const ComponentType type): m_type(type) {}

	virtual
	~Component() = default; //crear destructor virual en vez del destructor tradicional

	virtual void
	update(float deltaTime) = 0;

	virtual void
	render(Window window) = 0;

	ComponentType
		getType() const { return m_type; }

	//Todo esto es lo basico para darle uso a cualquier typo de componente dentro de nuestra clase
	//Solamente es una consulta


protected:
	ComponentType m_type;	//tipo de componente	
private:

};
