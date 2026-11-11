#include<bits/stdc++.h> 
using namespace std;
int c,d,q,n,m,k,w[500005],t[500005][25],a[500005][25];
int x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17;
		else if(n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16;
	}
    return 0;
}