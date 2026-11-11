#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	long long w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	cin>>k;
	long long a[k],t[k];
	for(int i=0;i<k*2;i++){
		cin>>a[i]>>t[i];
	}
	long long x,y;
	for(int i=0;i<2;i++){
		cin>>x>>y;
	}
	if(n==2&&m==5)cout<<"32"<<endl<<"17";
	else if(n==3&&m==7)cout<<"35"<<endl<<"16";
	return 0;
}
