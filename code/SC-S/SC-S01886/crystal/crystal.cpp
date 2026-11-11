#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,x;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a[i]={x,x+1};
		for(int j=0;j<=m;j++){
			x+=j;
			if(x=x+1){
				cout<<x<<endl;
			}
		}
	}
	return 0;
}