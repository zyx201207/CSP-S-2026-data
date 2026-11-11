#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int LG=32;
int n,m;
int cnt[LG],num[N][LG];
bool vis[N];
long long ans;
long long ksm(long long base,int power){
	long long res=1;
	while(power){
		if(power&1){
			res=res*base;
		}
		base*=base;
		power>>=1;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int lg=0;
		while(x){
			num[i][lg]=x&1;
			cnt[lg]+=(x&1);
			x/=2;
			lg++;
		}
	}
	for(int i=LG-1;i>=0;i--){
		if(cnt[i]>=m){
			ans+=ksm(2ll,i);
			for(int j=1;j<=n;j++){
				if(!vis[j] && num[j][i]==0){
					vis[j]=true;
					for(int k=0;k<=LG-1;k++){
						cnt[k]-=num[j][k];
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
