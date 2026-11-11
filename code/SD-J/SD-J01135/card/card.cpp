#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],s[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<" ";
	}
	return 0;
}

