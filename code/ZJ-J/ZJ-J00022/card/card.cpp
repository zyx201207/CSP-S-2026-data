#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int n,m,i,j,k,t,x,a[N],b[N],c[N],d[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)c[j]=0;
		t=0;
		for(j=i;j<=n;j++){
			if(c[a[j]]>0){
				x=c[a[j]];
				for(k=t;k>=x;k--)c[b[k]]=0,b[k]=0,t--;
			}
			t++,b[t]=a[j],c[a[j]]=t;
		}
		for(j=1;j<=t;j++)d[b[j]]++;
	}
	for(i=1;i<=m;i++)cout<<d[i]<<" ";
}
//by wild cat