#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,a[N],ans,cnt;
bool w[N][31],b[N];
vector<int> y[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int now=a[i];
		for(int j=0;j<31;j++){
			w[i][j]=now%2;
			now/=2;
			if(w[i][j]){
				y[j].push_back(i);
			}
		}
	}
	for(int mj=30;mj>=0;mj--){
		if(y[mj].size()>=m){
			for(auto now:y[mj]){
				b[now]=1;
			}
			for(int i=mj-1;i>=0;i--){
				cnt=0;
				for(int j=1;j<=n;j++){
					if(!b[j]) continue;
					if(w[j][i]) cnt++;
				}
				if(cnt>=m){
					for(int j=1;j<=n;j++){
						if(!b[j]) continue;
						if(!w[j][i]) b[j]=0;
					}
				}
			}
			cnt=0;
			bool bj=0;
			for(int i=1;i<=n;i++){
				if(cnt==m) continue;
				if(!b[i]) continue;
				if(bj==0){
					ans=a[i];
					bj=1;
					continue;
				}
				ans=(ans&a[i]);
				cnt++;
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
