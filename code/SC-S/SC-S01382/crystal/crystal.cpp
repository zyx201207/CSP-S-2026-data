#include<bits/stdc++.h>
#define endline cout<<"\n"
using namespace std;
//I ? ccf
const int N=5e5+5;
long long n,ans=1;
long long m,a[N];
long long cf[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		cf[i]=a[i+1]-a[i];
	}long long l=n-1,r=n;
	long long all=cf[n-1],bas=cf[n-1];
	while(true){
//		cout<<l<<' '<<r<<' '<<all<<'\n';
		if(l<=0) break;
		else if(l>=r) l--;
		else if(all<=m){
			ans=max(r-l+1,ans);
			all=all+bas+cf[--l];
			bas+=cf[l];
		}else{
			all-=(r-l)*cf[--r];
			bas-=cf[r];
		}
	}cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/