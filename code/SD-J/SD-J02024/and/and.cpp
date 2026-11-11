#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long st[N];
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	int n,m;
	long long maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(m==2){
		
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
			maxx=max(maxx,a[i] & a[j]);
		}
	}
	cout<<maxx;
	}
	if(m==1){
		for(int i=1;i<n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	return 0;
}
