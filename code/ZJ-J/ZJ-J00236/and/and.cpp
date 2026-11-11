#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,arr[N];
int w[N][35];
bool used[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	for(int i=1;i<=n;++i){
		int num=arr[i],j=0;
		while(num){
			w[i][j++]=num%2;
			num/=2;
		}
	}
	for(int i=31;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(!used[j]&&w[j][i]){
				++cnt;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;++j){
				if(!used[j]&&!w[j][i]){
					used[j]=true;
				}
			}
		}
	}
	int ans=pow(2,30)-1;
	for(int i=1;i<=n;++i){
		if(!used[i]){
			ans=ans&arr[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}