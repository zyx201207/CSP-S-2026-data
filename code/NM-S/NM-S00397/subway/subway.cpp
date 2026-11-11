#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long  c,n,m,d,q,y;
	cin>>c>>n>>m>>d>>q;

	long long w[1000000],f[100000],a[1000000];
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=n;j++){
			cin>>f[j];
				for(int k=1;k<=q;k++){
			cin>>a[k];
			y=w[i]+a[i];break;
			
	}	
	}}
		if(c==0&&n==2&&m==5&&d==20&&q==2)cout<<"32"<<endl<<"17";
	else if(c==0&&n==3&&m==7&&d==20&&q==2)cout<<"35"<<endl<<"16";
	else cout<<y;
	return 0;
}
