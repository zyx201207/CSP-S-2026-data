#include<bits/stdc++.h> 
using namespace std;
#define int long long 
const int N=5e5+5,M=3e5+5;
int a[N],n,m,pre[M],sum[M],b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		b[0]=1;
		memset(pre,0,sizeof(pre));
		memset(b,0,sizeof(b));
		int d=1;
		for(int j=i;j<=n;j++){
			//d+=b[j];
			if(pre[a[j]]>0){
				b[pre[a[j]]]--,b[j]++;
				for(int k=pre[a[j]];k<j;k++)pre[a[k]]=0;
			}
			pre[a[j]]=j;
		}
		int c=1;
		for(int j=i;j<=n;j++){
			c+=b[j];
			if(c>0) sum[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

//4 3  1 2 1 3
//10 3 3 1 2 1 3 2 3 1 2 1

