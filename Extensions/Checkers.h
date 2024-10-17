#pragma once

namespace Operators
{
	struct No{};
	template<typename type, typename arg = type> No operator<=(const type&, const arg&);
	template<typename type, typename arg = type> No operator>=(const type&, const arg&);
	//template<typename type, typename arg = type> No operator>(const type&, const arg&);

	template<typename type, typename arg = type>
	struct LessEqualYes
	{
		enum { value = !std::is_same<decltype(std::declval<type>() <= std::declval<arg>()), No>::value };
	};

	template<typename type, typename arg = type>
	struct GreaterEqualYes
	{
		enum { value = !std::is_same<decltype(std::declval<type>() >= std::declval<arg>()), No>::value };
	};

	template<typename type, typename arg = type>
	struct GreaterYes
	{
		enum { value = !std::is_same<decltype(std::declval<type>() > std::declval<arg>()), No>::value };
	};
};