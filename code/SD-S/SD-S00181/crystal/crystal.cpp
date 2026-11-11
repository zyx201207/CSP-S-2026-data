#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int s[N];
int ans;
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*(x-1)-s[i-1]+s[i-x]<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
			ans=l;
		} else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
