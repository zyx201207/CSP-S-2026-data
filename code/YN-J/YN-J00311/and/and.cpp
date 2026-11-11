#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int,int>;

const int N=2e5+5;
int m,n;
int a[N];
int sp_6;
bool b[N][35];

bool D[N];

void solve(){
	cin>>n>>m;
	sp_6=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sp_6=max(sp_6,a[i]);
	}
	if(m==1){
		cout<<sp_6<<endl;
		return;
	}
	for(int i=30;i>=0;i--){
		int k=(1<<i);
		for(int j=1;j<=n;j++){
			b[j][i]=((a[j]&k)!=0);
		}
	}

	
	int ans=0;
	for(int B=30;B>=0;B--){
		int num=0;
		for(int i=1;i<=n;i++){
			if(D[i]){
				continue;
			}
			num+=b[i][B];
		}
		if(num<m){
			continue;
		}else{
			ans+=(1<<B);
			for(int i=1;i<=n;i++){
				if(D[i]){
					continue;
				}
				if(b[i][B]==0){
					D[i]=1;
				}
			}
		}
	}
	cout<<ans<<endl;
}

int t_;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	t_=1;
//	cin>>t_;
	while(t_--){
		solve();
	}
	
//	cout.flush();
	
	return 0;
}
