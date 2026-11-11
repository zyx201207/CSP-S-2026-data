#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],s[N],w[N],ans;
void chai(long long x,int fh){
	int cc=0;
	while(x){
		if(x&1)w[cc]+=fh;
		x/=2;
		cc++;
	}
	return;
}
bool vis[N];
void slove(){
	for(int i=31;i>=0;i--){
		if(w[i]>=m){
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(vis[j])continue;
				if(!((a[j]>>i)&1)){
					vis[j]=1;
					chai(a[j],-1);
				}
			}
		}
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		chai(a[i],1);
	}
	slove();
	cout<<ans;
	return 0;
}
