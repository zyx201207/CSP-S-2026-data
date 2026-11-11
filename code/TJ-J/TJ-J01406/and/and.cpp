#include<bits/stdc++.h>
using namespace std;
int n,m,s[2000005],maxn=-10,i,j;
int fd(int i,int j,int m){
	for(int j=i;j<=n;j++)
	    maxn=max(s[i]&s[j],maxn);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		x=fd(i,j,m);
	}
	cout<<x;
	return 0;
}

