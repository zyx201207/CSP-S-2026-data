#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e5+5;
int n,a[N],ans=1;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		m-=i;
		if(m<0)break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}