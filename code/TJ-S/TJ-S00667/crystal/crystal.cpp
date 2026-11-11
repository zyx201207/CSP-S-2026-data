#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L=5e5+10;
int n,m,a[L],ans,s[L],res;
int get(int i,int j){
	return s[j]-(s[i-1]+(a[j]-a[i-1])*(i-1));
}
bool can(int x){
	for(int i=1;i+x-1<=n;i++){		
		res=get(i,i+x-1);
		if(res<=m){
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
	sort(a+1,a+n+1);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(can(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
