#include<bits/stdc++.h>
#define int long long
#define MAXN 510
using namespace std;
struct node{
	int wt,nu,zt,mo;
};
struct xl{
	int l1,l2,l3;
};
xl d[10];
node a[MAXN],b[MAXN];
struct nodee{
	int qd,zd;
};
nodee c[10010];
int k[5],hu;
int ee(int x,int y,int z){
	int s1=0,s2=0,s3=0;
	for(int i=1;i<=z;i++){
		if(d[i].l1==x)s1++;
		if(d[i].l2==x)s2++;
		if(d[i].l3==x)s3++;
		if(d[i].l1==y)s1++;
		if(d[i].l2==y)s2++;
		if(d[i].l3==y)s3++;
	}
	if(s1==2){
		hu=1;
		return 1;
	}
	if(s2==2){
		hu=2;
		return 1;
	}
	if(s3==2){
		hu=3;
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q,N,sum=0;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i].wt;
		a[i].nu=i;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];i++){
			cin>>N;
			if(n==1){
				d[i].l1=N;
			}else if(n==2){
				d[i].l2=N;
			}else if(n==3){
				d[i].l3=N;
			}
			if(a[N].zt!=0){
				a[N].mo++;
				cin>>b[N].zt;
				b[N].nu=a[N].nu;
			}else{
				cin>>a[N].zt;
			}
		}
	}
	for(int i=1;i<=q;i++)cin>>c[i].qd>>c[i].zd;
	for(int i=1;i<=q;i++){
		if(ee(c[i].qd,c[i].zd,n)){
			if(hu==1){
				sum+=a[c[i].qd].wt+a[c[i].qd].zt+a[c[i].zd].wt+a[c[i].zd].zt;
			}
		}
	}
	cout<<sum;
	return 0;
}