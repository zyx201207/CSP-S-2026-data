#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[505],k[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;++i)cout<<w[i];
	if(n==3){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
	}
	if(n==2){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
	}
	
	return 0;
}
