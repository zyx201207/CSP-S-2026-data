#include<bits/stdc++.h>
using namespace std;
int a1[1000005],w[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a,b,c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>c;
	for(int j=1;j<=2c;j++){
		cin>>a1[j];
		
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		if(a-b==1)
		{
			s=w[a]+w[b]+a1[1];
			cout<<s;
		}
	}
	return 0;
}
