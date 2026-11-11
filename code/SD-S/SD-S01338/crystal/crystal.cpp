#include<bits/stdc++.h>
using namespace std;
/*====================*/
#define endl '\n'
/*====================*/
const int N=5e5+10;
const int INF=0x7f7f7f7f;
/*====================*/
int a[N],cur[N],t[N];
/*====================*/
void Solve(void){
	int n,m,aver=0,maxx=-INF,ans=0;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=1;j<=i;++j){
			if(a[i]==t[j]) t[j]++;
		}
	}
	for(int i=1;i<=n;++i) maxx=max(t[i],maxx);
	if(maxx>1)  aver=maxx;
	else aver=aver/n;
	for(int i=1;i<=n;++i) cur[i]=(a[i]-aver>0?a[i]-aver:aver-a[i]);
	sort(cur+1,cur+n+1);
	for(int i=1;i<=n;++i){
		if(cur[i]==ans) continue;
		else {if(m>=m-cur[i]) ans++,m-=cur[i];}
	}
	cout<<ans;
}
/*====================*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Solve();
	return 0;
}
