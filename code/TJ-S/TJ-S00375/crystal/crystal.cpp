#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long total,op_times;
	std::vector<long long> data_list;
	std::cin>>total>>op_times;
	long long item;
	data_list.reserve(total);
	for(long long i = 0;i < total;i++)
	{
		std::cin>>item;
		data_list.push_back(item);
	}

	int ans2 = 0 ,count2 = 0;
	std::sort(data_list.begin(),data_list.end(),std::greater<long long>());
	if(total <= 1e9)
	{
		for(int i = 0 ; i < total;i++)
		{
			long long base = data_list.at(i);
			for(int j = 0 ; j < i ;j++)
			{
				if(op_times >= base - data_list.at(j)){
					op_times -= (base - data_list.at(j));
					count2++;
				}
			}
			if(count2 > ans2)
				ans2 = count2;
			count2 = 0;
		}
		std::cout<<ans2;
		return 0;		
	}
	else{
		long long ans = 0;
		long long count = 1;
		for(long long i = 1 ;i < total;i++)
		{
			ans += i;
			if(ans > op_times)break;
			count += 1;
		}
		std::cout<<count;
		return 0;
		
	}
	return 0;
}
