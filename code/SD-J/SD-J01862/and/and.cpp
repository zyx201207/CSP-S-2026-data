#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(ll)a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
