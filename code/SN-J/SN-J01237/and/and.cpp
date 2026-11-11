#include<bits/stdc++.h> 
using namespace std;
const int N=1e8+10;
int n,m,a[N],b[N],ans=0,anss=0,maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		anss++; 
	}	
	for(int i=anss;i>=1;i--){
		ans=(a[i]&a[i-1]);
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 
