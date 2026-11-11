#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(register int i=1;i<=n;++i)cin>>a[i];
	for(int i=30;i>=0;--i){
		register int cnt=0;
		for(register int j=1;j<=n;++j){
			if(a[j]&(1<<i))++cnt;
		}
		if(cnt<m){
			for(register int j=1;j<=n;++j){
				if(a[j]&(1<<i))a[j]-=(1<<i);
			}
		}else{
			ans+=(1<<i);
			for(register int j=1;j<=n;++j){
				if((a[j]&(1<<i))==0)a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}