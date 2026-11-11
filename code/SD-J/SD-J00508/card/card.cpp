#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],tp[N],v[N];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s="";
		memset(tp,0,sizeof tp);
		for(int j=i;j<=n;j++)
		{
			tp[a[j]]++;
			s+=a[j]+'0';
			if(tp[a[j]]==2)
			{
				int l=s.size();
				for(int k=s.find(a[j]+'0')+1;k<l;k++)
				{
					tp[s[k]-'0']--;
				}
				s.erase(s.find(a[j]+'0'));
				s+=a[j]+'0';
			}
		}
		int l=s.size();
		for(int j=0;j<l;j++)
		{
			v[s[j]-'0']++;	
			//cout<<s[j]-'0'<<endl;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

3 1 4


10 3
3 1 2 1 3 2 3 1 2 1
*/
