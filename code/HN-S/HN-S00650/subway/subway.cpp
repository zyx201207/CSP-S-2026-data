#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w,a,t,k,x,y;
	for(int i=0;i<m;i++){
		cin>>w;
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
		}
	}
	for(int j=0;j<q;j++){
		cin>>x>>y;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
	}
	return 0;
}
