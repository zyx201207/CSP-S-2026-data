#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005],c[100005],p,s[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		p=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]<p&&b[a[j]]>0){
				p=b[a[j]];
			}
			b[a[j]]=p;
			c[p++]=a[j];
		}
		for(int j=1;j<=p-1;j++){
			s[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	
	return 0;
}