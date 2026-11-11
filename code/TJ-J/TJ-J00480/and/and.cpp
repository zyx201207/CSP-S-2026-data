#include <iostream>
#include <cstdio>
#include <vector>
using namespace std; 

int main()
{
	freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	vector<long long>arrayer;//arrayer是读入的数组 
	//arrayer.reserve(10000);

	long long count = 0;//count是读入数组的长度 
	long long require_count = 0;//require_count是读入的要求数字的个数 
	cin>>count;
	cin>>require_count; 
	for(int i = 0; i<count;i++)
	{
		long long a = 0;
		cin>>a;
		arrayer.push_back(a);
	}
	vector<long long>answer_size;
	answer_size.reserve(10000);
	
	//最高位进1，然后每次遍历检查是否进位 
	long long cacu_size[require_count] = {0};
	cout<<arrayer.size()<<endl;
	
	
	for(long long i = 0;i<arrayer.size()-2;i++)
	{
		cacu_size[i] = arrayer[i];
		for(long long p = i+1;i<arrayer.size()-1;p++)
		{
			cacu_size[p] = arrayer[p];
			answer_size.push_back(cacu_size[i]&cacu_size[p]) ; 
		}
	}
	
	
	
	/*
	check:
	for(int i = 0; i<answer_size.size()-1;i++)
	{
		long long exc = 0;
		if(answer_size[i]>answer_size[i+1])
			{
			exc = answer_size[i]; 
			answer_size[i] = answer_size[i+1]; 
			answer_size[i+1] = exc;}
	 } 
	 for(int i =0;i<answer_size.size()-1;i++)
	 {
	 	if(answer_size[i]>answer_size[i+1])
	 	goto check;
	 }
	 cout<<answer_size[0]<<endl;
	 */
	fclose(stdin);
	fclose(stdout);
	return 0;
}
