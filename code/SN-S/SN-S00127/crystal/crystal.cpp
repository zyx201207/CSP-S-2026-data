#include<bits/stdc++.h>
using namespace std;
long long N[600000];
long long M[600000];
int n;
long long m;
bool check(int k){
	if(k==1) return true;
	else{
		M[k]=0;
		for(int i=1;i<k;i++){
			M[k]+=N[k]-N[i];
		}
		if(M[k]<=m) return true;
		for(int i=k+1;i<=n;i++){
			M[i]=M[i-1]+(k-1)*N[i]-k*N[i-1]+N[i-k];
			if(M[i]<=m) return true; 
		}
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>N[i];
	}
	sort(N+1,N+n+1);
	int l=1,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		//cout<<l<<" "<<r<<" "<<mid<<" ";
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
