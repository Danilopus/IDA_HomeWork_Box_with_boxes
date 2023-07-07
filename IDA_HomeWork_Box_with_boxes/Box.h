#pragma once
#include <vector>

//#include "Service functions.h"

class Box
{
	struct BoxDimensions { int _width; int _height; int _depth; } _dimensions;
	std::vector<Box*> _inner_boxes_list;
public:
	Box(int width, int height, int depth)
	{
		_dimensions._depth = depth;
		_dimensions._height = height;
		_dimensions._width = width;
	}
	Box& pushfront(Box& new_value)
	{
		if (_inner_boxes_list.size() == 0)
		{
			_inner_boxes_list.push_back(&new_value);
			return *this;
		}
		for(int i=_inner_boxes_list.size(); i>0;--i)
		{
			_inner_boxes_list.push_back(_inner_boxes_list[_inner_boxes_list.size() - 1]); //сохраняем последний элемент в новую ячейку
			_inner_boxes_list[i] = _inner_boxes_list[i - 1];
		}
		_inner_boxes_list[0] = &new_value;
		return *this;
	}
	Box& pushback(Box& new_value)
	{
		_inner_boxes_list.push_back(&new_value);

		return *this;
	}
	Box& popfront()
	{
		for (int i = 0; i<_inner_boxes_list.size(); --i)
		{
			_inner_boxes_list[i] = _inner_boxes_list[i + 1];
		}		
		_inner_boxes_list.pop_back();
		return *this;
	}
	Box& popback()
	{
		_inner_boxes_list.pop_back();
		return *this;
	}
	Box& insert(size_t pos, Box& new_value)
	{
		_inner_boxes_list.insert(_inner_boxes_list.begin()+pos, &new_value);
		return *this;
	}
	Box& clear()
	{
		_inner_boxes_list.clear();
		return *this;
	}

	size_t size() 
	{ 
		size_t inner_size = 0;
		if (_inner_boxes_list.size())
		{
			for (int i = 0; i < _inner_boxes_list.size(); i++)
				inner_size += _inner_boxes_list[i]->size();
		}		
		return 	(inner_size+_inner_boxes_list.size());
	}

	//Box* begin() { return _inner_boxes_list.begin(); }
	//Box* end() { return _inner_boxes_list.end(); }

	 //Shows ---------------------------------------------------------------
	void ShowValues()
	{
		std::cout << "/n_height -> " << _dimensions._height;
		std::cout << "/n_width -> " << _dimensions._width;
		std::cout << "/n_depth -> " << _dimensions._depth;
	}


	//Overload operators - reference returned -----------------------------------------	

	/*
	Box& operator + (const Box& Box_obj) const

	{
		Box& new_container = *new Box;
		for (size_t i = 0; i < _size; i++)
			new_container.pushback(_values_list[i]);

		for (size_t i = 0; i < Box_obj._size; i++)
			new_container.pushback(Box_obj._values_list[i]);

		return new_container;
	}
	*/
	/*
	//Box<any>& operator = (const Box<any>& Box_obj)
	Box& operator = (const Box& Box_obj)
	{
		if (_size >= Box_obj._size)
		{
			for (size_t i = 0; i < Box_obj._size; i++)
				_values_list[i] = Box_obj[i];
			_size = Box_obj._size;
			if (_size < _capacity / 2) Shrink_capacity();
		}
		else
		{
			any* new_list_for_copie = new any[Box_obj._capacity];
			for (size_t i = 0; i < Box_obj._size; i++)
				new_list_for_copie[i] = Box_obj[i];
			delete[] _values_list;
			_values_list = new_list_for_copie;
			_size = Box_obj._size;
			_capacity = Box_obj._capacity;
		}
		return *this;
	}
	*/

	Box& operator [ ] (size_t index) { return *_inner_boxes_list[index]; }
	//Box& operator [ ] (size_t index) const { return *(_inner_boxes_list.begin() + index); }


	/*
	friend std::ostream& operator << (std::ostream& out, Box* Box_obj)
	{
		if (Box_obj->_values_list == nullptr)
			return out << "[no data]";

		out << "[ ";
		for (int i = 0; i < Box_obj->_size; i++)
			//out << Box_obj->_values_list[i] << " | ";
			out << (*Box_obj)[i] << " | ";
		out << "\b\b]";
		return out;
	}
	friend std::ostream& operator << (std::ostream& out, Box& Box_obj)
	{
		if (Box_obj._values_list == nullptr)
			return out << "[no data]";

		out << "[ ";
		for (int i = 0; i < Box_obj._size; i++)
			//		out << Box_obj._values_list[i] << " | ";
			out << Box_obj[i] << " | ";
		out << "\b\b]";
		return out;
	}
	friend std::istream& operator >> (std::istream& in, Box& Box_obj)
	{
		//Box_obj.pushback(Get_LL_SA());
		return in;
	}
	*/
};




