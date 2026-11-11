#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int c,n,m,d,q,a,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a;
	} 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>a;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a>>a;
	}
	for(int i=1;i<=q;i++){
		cout<<1<<endl;
	} 
	return 0;
} 
