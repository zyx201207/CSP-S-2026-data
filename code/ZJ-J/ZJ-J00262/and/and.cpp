#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,a[N],l,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>l;
    for(int i=2;i<=n;i++){
    	cin>>a[i];
    	l=l and a[i];
	}
	sort(a+1,a+1+n);
	if(m==n){
		cout<<l;
	}
	else if(m==1){
		cout<<a[n];
	}
	else if(m==n-1){
		cout<<l || a[n];
	}
	else{
		cout<<a[n-m+1];
	}
	return 0;
}//Trick||Treat!
