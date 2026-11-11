#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,m;
int a[N][33]={0};
bool vis[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	int maxv=0;
	for(int i=1;i<=n;i++){
		int x,cnt=0;
		cin>>x;
		while(x){
			if(x&1){
				a[i][cnt]=1;
			}
			x>>=1;
			cnt++;
		}
		maxv=max(maxv,cnt);
	}
	int now=maxv,ans=0;
	memset(vis,1,sizeof(vis));
	while(true){
		int cnt=0;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				if(a[i][now]){
					cnt++;
				}else{
					v.push_back(i);
				}
			}
		}
		if(cnt>=m){
			for(int i=0;i<v.size();i++){
				vis[v[i]]=0;
			}
			ans+=pow(2,now);
		}
		if(now==0){
			break;
		}
		now--;
	}
	cout<<ans;
	return 0;
}
