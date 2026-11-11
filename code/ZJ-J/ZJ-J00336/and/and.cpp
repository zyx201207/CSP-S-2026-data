#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m;
ll a[N];
vector<int>v[32];
ll ans;
bool flag[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
//			cout<<int(flag[j])<<" ";
			if(!flag[j]) cnt+=bool(a[j]&(1ll<<i));
//			cout<<cnt<<"  ";
		}
//		cout<<cnt<<"\n";
//		for(int j=1;j<=n;j++) cout<<int(flag[j])<<" ";
//		cout<<"\n";
		if(cnt>=m) {
			ans|=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1ll<<i))){
					flag[j]=1;
				}
			}
		}
//		for(int j=1;j<=n;j++) cout<<int(flag[j])<<" ";
//		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
//yellow/orange
//ez
//seconded