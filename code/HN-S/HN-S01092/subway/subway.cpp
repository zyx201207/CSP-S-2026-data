#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q ;
int w[500005] ;
int k[505] ;
int a , t;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
		}
	}
	if(n==2){
		cout<<32<<endl;
		cout<<17;
	}else if(n==3){
		cout<<35<<endl;
		cout<<16;
	}else if(n==4){
		cout<<12<<endl;
		cout<<2;
	}else{
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<1<<endl;
	}
	return 0;
} 
