#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
const int M=32;
int arr[N];
bool ned[M];
bool check(int x,int d){
	for(int i=29;i!=-1;i--)
		if(ned[i]&&(!((x>>i)&1))) return false;
	if((x>>d)&1) return true;
	return false;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	int ans=0;
	for(int i=29;i!=-1;i--){
		int tot=0;
		for(int j=1;j<=n;j++)
			if(check(arr[j],i)) tot++;
		if(tot>=m){ned[i]=true;ans+=(1<<i);}
	}	
	cout<<ans<<"\n";
	return 0;
}

