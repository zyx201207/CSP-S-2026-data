#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=-1e12;
int n,m,a[500101],ans,sum,b[500101];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//a[0]=N;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		if(b[i]>m){
			cout<<i-1; 
			return 0;
		}
	}
	return 0;
}
