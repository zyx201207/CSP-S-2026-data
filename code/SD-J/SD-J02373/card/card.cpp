#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=2e5+10,M=3e5+10;
int a[N],ans[M],p[M]//下标
,v[M]//下标
,t[M]//判断
;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		memset(t,0,sizeof t);
		for(int j=i;j<=n;j++){
			if(t[j]!=1 && t[v[a[j]]]!=1){
				for(int k=v[a[j]];k<j;k++){
					t[k]=1;
				}	
			}
			v[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(p[j]>=i){
				if(t[p[j]]!=1){
					ans[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
