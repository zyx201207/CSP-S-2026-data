#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],zd=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	if(m==1){
		cout<<zd;
		return 0;
	}
	else{
		cout<<a[n];
		return 0;
	}
}
