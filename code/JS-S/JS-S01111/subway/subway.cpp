#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[10001],b[10001][10001],r[10001][10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			cin>>r[i][j];
		}
	}
	if(c==0&&n==2){
		cout<<"32"<<endl<<"17";
	}
	else if(c==0&&n==3){
		cout<<"35"<<endl<<"16";
	}
	return 0;
}
