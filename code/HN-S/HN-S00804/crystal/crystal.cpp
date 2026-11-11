#include<bits/stdc++.h>
using namespace std;
long long int n,a[500000+5],s=0,t;
long long int m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0) cout<<"0";
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		t=1,s=0;
		for(int j=1;j<=i;j++){
			s=s+a[i]-a[j];
			t++;
		}
		if(s==m){
			cout<<t-1;
			return 0;
		}
	}
	return 0;
} 
