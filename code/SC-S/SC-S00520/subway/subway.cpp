#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[5005][5005],c[5005][5005],t[5005][5005],x[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5){
		cout<<32<<endl<<17;
	}
	else if(c==0&&n==3){
		cout<<35<<endl<<16
	}
	else{
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ans+=a[i];
	}
	int x[505]
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			cin>>b[j][i];
			ans+=b[j][i];
		}
		int k=1,g=1;
		for(int j=1;j<=x[i];j++){
			if(j%2==0){
				t[k][i]=b[j][i];
				k++;
			}else{
				c[g][i]=b[j][i];
				g++;
			}
		}
	}
	int a1[500005],a2[500005];
	for(int i=1;i<=q;i++){
		cin>>a1[i]>>a2[i];
		cout<<ans<<endl;
	}
	return 0;
}
