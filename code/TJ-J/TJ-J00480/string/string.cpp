#include <iostream>
#include <cstdio>
#include <vector>
using namespace std; 
//:)
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	vector<char>stringer(0);
	stringer.reserve(100000);
	long long answer = 0;
	long long count = 0;
	cin>>count; 
	for(long long i = 0; i<count;i++)
	{
		long long cip = 0;
		char a = 0;
		cin>>cip;
		cin>>a;
		for(long long p = 0;p<cip;p++)
		{
			stringer.push_back(a);
		}
	}
	if(stringer.size()%2!=0)
	{
		for(int i = 0;i<(stringer.size()-1)/2;i++)
		{
			if(stringer[i]!=stringer[(stringer.size())-1-i])
			{
				answer++;
			}
			
		}
		
	}
	else{
		for(int i = 0;i<(stringer.size()/2);i++)
		{
			if(stringer[i]!=stringer[(stringer.size()-1)-i])
			{
				answer++;
			}
			
		}
		
	}
	cout<<answer<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
