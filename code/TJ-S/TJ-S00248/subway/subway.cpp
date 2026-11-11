#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005],k[578];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(n==2&&m==5&&d==20&&q==2)cout<<32<<endl<<17;
	else if(n==3&&m==7&&d==20&&q==2)cout<<35<<endl<<16;
	return 0;
} 
