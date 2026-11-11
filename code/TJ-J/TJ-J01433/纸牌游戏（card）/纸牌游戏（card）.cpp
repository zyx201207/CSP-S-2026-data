#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0},b[500005]={0};
int main(){
	freopen("Ö½ÅÆÓÎÏ·£¨card£©.in","r",stdin);
	freopen("Ö½ÅÆÓÎÏ·£¨card£©.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int n,m,pd;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			pd++;
		}
	}
	if(pd==n){
		for(int i=m;i>=1;i--){
			cout<<i<<" ";
		}
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<"0 ";
		}
	}
	return 0;
}
