#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g=a[2]-a[1];
	int cnt=1;
	while(m>=g){
		m-=g;
		g+=g;
		cnt++;
	}
	cout<<cnt;
	
	return 0;//67676767767676767676767677676767676767676767676767767676767767676767677676767676767676767676767676767676767767676767676767677677676767677676767676676767667
}
