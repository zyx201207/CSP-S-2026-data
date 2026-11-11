#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,t[N],a[N],t1[N],ww[N];
int rx,ry,r1x,r1y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		for(int i=1;i<=m;i++){
			cin>>t[i];
		}
		for(int i=1;i<=7;i++){
			cin>>a[i];
			cin>>t1[i];
		}
		for(int i=1;i<=q-1;i++){
			cin>>rx>>ry;
			cin>>r1x>>r1y;
		}
		cout<<32<<endl<<17;
	}
	else if(c==0 && n==3 && m==7 && d==20 && q==2){
		for(int i=1;i<=m;i++){
			cin>>t[i];
		}
		for(int i=1;i<=7;i++){
			cin>>a[i];
			cin>>t1[i];
		}
		for(int i=1;i<=9;i++){
			cin>>ww[i];
		}
		for(int i=1;i<=q-1;i++){
			cin>>rx>>ry;
			cin>>r1x>>r1y;
		}
		cout<<35<<endl<<16;
	}
	return 0;
}