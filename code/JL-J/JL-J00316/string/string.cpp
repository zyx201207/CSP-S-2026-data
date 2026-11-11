#include<bits/stdc++.h>
using namespace std;
struct str
{
	int num;
	char ch;
}d[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string ans="";
	for(int i=0;i<n;i++)
	{
		cin>>d[i].num>>d[i].ch;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d[i].num;j++)
			ans.push_back(d[i].ch);
	}
	string t=ans;
	reverse(t.begin(),t.end());
	int len=ans.size();
	long long cnt=0;
	if(t==ans)
	{
		cout<<0<<endl;
	}
	else
	{
		long long left=0,right=len-1;
		while(left<=right)
		{
			cnt+=(ans[left]==ans[right])? 0 : 1;
			left++;
			right--;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
