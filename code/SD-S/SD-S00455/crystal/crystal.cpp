#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

#define int long long

using namespace std;

const int N=5e5+10;
int n,m;
int v[N];
__int128 s[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+v[i];
	}
//	cout<<"\n";
	int ans=-2e9;
	int l=1,r=1;
	__int128 exsum=0,fasum=0;
	while(l<=n&&r<=n){
		exsum=v[r]*(r-l+1);		
		fasum=s[r]-s[l-1];
		__int128 res=exsum-fasum;
////		cout<<exsum<<" "<<fasum<<"\n";
		
		if(res<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
//	cout<<l<<" "<<r<<" ";
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
