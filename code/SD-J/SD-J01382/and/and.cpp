#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
ll pw[40];
bool ok[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	pw[0]=1;
	for(int i=1;i<=30;i++) pw[i]=(pw[i-1]<<1);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ok[i]=1;
	}
	ll ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(ok[j]){
				if(a[j]&pw[i]){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			ans+=pw[i];
			for(int j=1;j<=n;j++){
				if(ok[j]){
					ok[j]=(a[j]&pw[i]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
