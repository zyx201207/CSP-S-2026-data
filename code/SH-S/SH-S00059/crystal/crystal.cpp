#include<bits/stdc++.h>
#define int long long
using namespace std;
int nm[600000];
int sm[600000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,mx=0,nk=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
	}
	sort(nm+1,nm+n+1);
	for(int i=1;i<=n;i++){
		sm[i]=nm[i]+sm[i-1];
	}
	for(int i=1;i<=n;i++){
		if((nm[i]*(i-nk)-sm[i]+sm[nk])<=m){
			mx=max(i-nk,mx);
		}
		else{
			nk++;
		}
	}
	cout<<mx<<endl;
	return 0;
} 
