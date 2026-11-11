#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int n,m;
int a[N];
int remain;
int sum=0;
int maxx=-1e9;

void solve(){
	cin>>n>>m;	
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum=0;
		for (int j=i+1;j<=n;j++){
			sum+=a[j-1];
			if (abs(a[j]*(j-i)-sum)<=m){
				if (abs(a[j]*(j-i)-sum)>=maxx && j-i+1>remain){
					maxx=abs(a[j]*(j-i)-sum);
					remain=j-i+1;
				}
			}
		}
	}
	cout<<remain<<"\n";
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
