#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out"."w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[10005]={};
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=1+2k){
			cin>>a[i]>>t[i];
		}
	}
	sort(t+1,t+n+1);
	for(int k=1;k<=q;k++){
		int x,y;
		cin>>x>>y;
		cout<<t[k];
	}
} 
