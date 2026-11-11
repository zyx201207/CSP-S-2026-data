#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long int ans = 0;
	cin>>n;
	vector<long long int> num(n+1);
	vector<char> letter(n+1);
	for(int i = 1;i<=n;i++)
	{
		cin>>num[i]>>letter[i];
	}
	int a = 1,c = n;
	while(a != c)
	{
		if(letter[a] == letter[c])
		{
			a++;
		}
		if(num[a]>=num[c] && letter[a] != letter[c])
		{
			ans+=num[c];
			num[a]-=num[c];
			c--;
		}
		else if(num[a]<num[c] && letter[a]!=letter[c])
		{
			ans+=num[a];
			num[c]-=num[a];
			a++;
		}
	}
	cout<<ans;
	return 0;
}
