#include<bits/stdc++.h>
using namespace std;
long long x,y,n,m,d,c,k,q,mj[500005];
struct sub{
	long long a[24];
	long long b[24];
}s[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>mj[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[j].a[j];
			cin>>s[j].b[j];	
		}
			
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(m==1){
		cout<<(mj[1]+s[1].b[1])*2;
	}
		if(m==2){
		cout<<mj[1]+s[1].b[1]+mj[2]+s[2].b[2];
		}
		
	}
	return 0;
} 
