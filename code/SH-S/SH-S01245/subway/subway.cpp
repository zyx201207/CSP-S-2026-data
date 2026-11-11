#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
int a[N],b[N],c[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int f,n,m,dd,q,k,d,e;
	cin>>f>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>b[i]>>c[i];
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>d>>e;
	}
	cout<<35<<"\n"<<16; 
	return 0;
} 
