#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int v[1000000];
int num[1000000];
bool ck(int o){
	for(int i=1;i<=n-o+1;i++){
		if((o*v[i+o-1])-(num[i+o-1]-num[i-1])<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		
	}
	sort(v+1,v+1+n);
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+v[i];
		
	}
 	int l=0;
 	int r=n+1;
 	while(l+1<r){
 		int mid=(l+r)/2;
		if(ck(mid)){
			l=mid;
		}else{
			r=mid;	
		}
	}
	cout<<l;
}

