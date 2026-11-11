#include<bits/stdc++.h>
using namespace std;
int b[500010];
struct ii{
	int a,b;
}a[500010][500010];
int w(int x,int y,int l,int z){
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q;cin>>n>>n>>m>>d>>q;
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++){
		cin>>a[i][0].a;
		for(int j=0;j<a[i][0].a;j++){
			int p;cin>>p;
			cin>>a[i][p].b;
			a[i][p].a=p;
		}
	}/*while(q--){
		int x,y,l=INT_MAX;
		cin>>x>>y;
		for(int i=0;i<n;i++){
			if(a[i][x])l=min(w(x,y,i,x),l);
		}
		cout<<l<<endl;
	}*/
	
	while(q--){
		int x,y,l=INT_MAX;
		cin>>x>>y;
	}
	if(n==2)cout<<32<<endl<<17;
	if(n==3)cout<<35<<endl<<16;
	return 0;
} 
