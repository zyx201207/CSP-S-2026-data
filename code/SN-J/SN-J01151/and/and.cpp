#include<bits/stdc++.h>
using namespace std;
#define int long long
bool mp[32][200001];
int a[200001];
int n,m;
bool ans[200001],ls[200001];
int now,lss,out;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans[i]=1;
		int x;
		cin>>x;
		a[i]=x;
		for(int j=1;j<=31;j++){
			if((1<<(j-1))&x){
				mp[j][i]=1;
			}
		}
	}now=n;
	for(int i=31;i>=1;i--){
		memcpy(ls,ans,sizeof ans);
		lss=now;
		for(int j=1;j<=n;j++){
			if(ls[j] && !mp[i][j])lss--;
			ls[j]&=mp[i][j];
		}
		if(lss>=m){
			now=lss;
			memcpy(ans,ls,sizeof ls);
			out|=(1<<(i-1));
		}
	}cout<<out;
	return 0;
}
