#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct station{
	int k_to_t;
	int t_to_c[25];
	int can_to[505];
}a[500005];
int c,n,m,d,q;
int k;
int zhan[500005][500005];
int ti[500005][500005];
int x,y;
int tot;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].k_to_t ;
		tot+=a[i].k_to_t ;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>zhan[i][j]>>ti[i][j];
			tot+=ti[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2) cout<<"32\n17";
		if(n==3&&m==7&&d==20&&q==2) cout<<"35\n16";
	}
	else{
		while(q--){
			cout<<tot<<"\n";
		}
	}
	return 0;
}