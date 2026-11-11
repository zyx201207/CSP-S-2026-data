#include <iostream>
#include <stdint.h>
#include <limits.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using i64 = int64_t;

bool valid(i64 energy_value[],i64 size,i64 pick,i64 points_add)
{
	i64 target_value = energy_value[pick];
	i64 i = 0;
	while(points_add > 0 && i < size)
	{

		if(points_add >= target_value - energy_value[i])
		{
			points_add -= target_value - energy_value[i];
			i++;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	i64 crystal_count;
	std::cin >> crystal_count;
	i64 points_add;
	std::cin >> points_add;
	
	i64 energy_value[crystal_count] = {};
	for(auto& val : energy_value)
		std::cin >> val;
	std::sort(energy_value,energy_value + crystal_count);
	
	i64 pick_left = 0, pick_right = crystal_count - 1,pick_mid = (pick_left + pick_right) / 2;
	i64 target_value = energy_value[0];
	while(pick_left < pick_right)
	{
		pick_mid = (pick_left + pick_right) / 2;
		if(valid(energy_value,crystal_count,pick_mid,points_add))
		{

			pick_left = pick_mid + 1;
			target_value = std::max(target_value,energy_value[pick_mid]);
		}
		else
		{
			pick_right = pick_mid - 1;
		}

	}
	
	i64 i = 0;
	while(points_add > 0 && i < crystal_count)
	{
		if(points_add >= target_value - energy_value[i] && energy_value[i] <= target_value)
		{
			points_add -= target_value - energy_value[i];
			energy_value[i] = target_value;
			i++;
		}
		else
			break;
	}
	
	
	i64 counter = 0;
	for(auto& val : energy_value)
	{
		if(val == target_value) 
			counter++;
	}
	
	std::cout << counter;
	return 0;
}
