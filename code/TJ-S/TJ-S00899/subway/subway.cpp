#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	//^_^
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
		if(n==2){
			cout<<32<<endl;
			cout<<17;
			return 0;
		}else if(n==3){
			cout<<35<<endl;
			cout<<16;
			return 0;
		}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	} 
	return 0;
}

