#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(false);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=30;i>=0;i--){
		long long mask=ans|(1ll<<i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&mask)==mask) {
				cnt++;
			}
		}
		if(cnt>=m){
			ans=mask;
		}                            
	}
	cout<<ans<<"\n";
}
