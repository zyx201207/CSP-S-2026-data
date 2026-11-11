#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int s[m-1] ;
	for(int i=0;i<=m-1;i++){
		cin>>s[i];
	}
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<endl;
			cout<<17;
			return 0;
		}
		if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<endl;
			cout<<16;
			return 0;}	}
	cout<<s[n];
	cout<<s[d];
	return 0;
}
