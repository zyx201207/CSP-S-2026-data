#include<bits/stdc++.h>
using namespace std;
const int N=2e9;
int n,m,a[N],maxx=-1;
void morand(int i,int nn,int ans){
	for(int j=i+1;j<=nn;j++){
		return morand(j,nn-1,ans&a[j+1]);
	}
	maxx=max(maxx,ans);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	morand(1,m,INT_MAX);
	cout<<maxx;
	return 0;
}
