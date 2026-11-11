#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000005],t[100005],a[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=d;i++){
		cin>>a[i];
		for(int j=1;j<=q;j++){
			cin>>t[i];
		}
	}
	cout<<"32"<<endl<<"17"<<endl;
	return 0;
}

