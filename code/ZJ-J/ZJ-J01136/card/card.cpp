#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005],f[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0 && f[b[a[j]]]==0){
				for(int k=b[a[j]];k<j-i+1;k++)
					f[k]=1;
			}
			b[a[j]]=j-i+1;f[a[j]]=0;
		}
		for(int j=1;j<=m;j++){
			if(f[b[j]]==0 && b[j]>0)
				c[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}
