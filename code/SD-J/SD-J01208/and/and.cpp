#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;

long long n,m,ans,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			ans = max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		ans = a[1];
		for(int i=2;i<=n;i++){
			ans = ans&a[i];
		}
		cout<<ans;
	}
	return 0;
} 
