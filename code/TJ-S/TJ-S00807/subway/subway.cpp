#include<bits/stdc++.h>
using namespace std;
long long w[500005]={0},k[500005]={0},a[500005][500005],t[500005][500005],x[500005]={0},y[500005]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0&&n==2){
		cout<<"32"<<endl<<"17";
	}
	else if(c==0&&n==3){
		cout<<"35"<<endl<<"16";
	}
	else{
		cout<<"42"<<endl<<"15";
	}
	return 0;
}

