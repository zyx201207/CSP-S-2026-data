//张展豪  SN-S00522 西安市远东第一中学 
#include<bits/stdc++.h>
using namespace std;
long long a[1000005]={0};
long long b[1000005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		if(a[i]>a[i-1]){
			if(x<=m){
				x+=a[i]-a[i-1];
			}
		}	
		else if(a[i]==a[i-1]) x+=0;
	}
	cout<<x;
	return 0;
}
