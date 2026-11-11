#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,lg=30;
bool vis[N],ist[N][lg];
long long ans=0,x;
int n,m,mt[lg];
void to0b(long long x,int id){
	int cnt=0;
	while(x>0){
		if(x%2){
			mt[cnt]++;
			ist[id][cnt]=true;
		}
		++cnt;
		x/=2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(ist,false,sizeof ist);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x); 
		to0b(x,i);
	}
	memset(vis,false,sizeof(vis));
	bool w=true;
	for(int i=lg-1;i>=0;i--){
		int sum=0;
		if(mt[i]>=m){
			for(int j=1;j<=n;j++){
				if(w){
					if(ist[j][i])vis[j]=true;
				}
				vis[j]&=ist[j][i];
				if(vis[j])sum++;
			}
			w=false;
			if(sum>=m)ans+=(1<<i);
			else {
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0; 
}
