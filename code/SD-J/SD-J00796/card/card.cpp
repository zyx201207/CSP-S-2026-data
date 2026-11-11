#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 5e5;
int n,m,a[N],t[N],dp[505][505];
bool f,ff;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f=1;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(f==0){
		for(int i = 1;i <= n;i++){
			t[a[i]]=i;
		}
		for(int i = 1;i <= m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	return 0;
}
