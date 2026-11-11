#include<bits/stdc++.h>
using namespace std;
int w[401],f[4001];
int c,n,m,d,q,sum=0;
struct sub{
	int a;
	int t;
	bool p=false;
}a[501][3];
int setr(int l,int r,int ui){
	int er=l,mi=0;
	if (!ui){
		for (int i=0;i<n;i++){
			if (a[i][0].a== l){
				mi=i;
				break;
			}
		}
		if (a[mi][1].a == r){
			return sum;
		}
		for (int i=0;i<n;i++){
			if (a[mi][0].a == a[i][1].a && mi != i && !(a[i][1].p)){
				sum+=a[mi][0].t+a[i][1].t;
				a[i][1].p=true;
				setr(a[i][1].a,r,1);
			}
		}
	}else{
		for (int i=0;i<n;i++){
			if (a[i][1].a== l){
				mi=i;
				break;
			}
		}
		if (l == r || a[mi][0].a == r){
			return sum;
		}
		for (int i=0;i<n;i++){
			if (a[mi][1].a == a[i][1].a && mi != i && !(a[i][1].p)){
				sum+=a[mi][1].t+a[i][1].t;
				a[i][1].p=true;
				setr(a[i][1].a,r,1);
			}else if(a[mi][1].a == a[i][0].a && mi != i && !(a[i][0].p)){
				sum+=a[mi][1].t+a[i][0].t;
				a[i][0].p=true;
				setr(a[i][0].a,r,0);
			}
		}
	}
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=0;i<n;i++){
		int u;
		cin>>u;
		for(int j=0;j<u;j++){
			cin>>a[i][j].a>>a[i][j].t;
		}
	}
	for (int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		sum=w[l];
		int j=0;
		j=setr(l,r,0);
		cout<<j+w[r]<<endl;
	}
	return 0;
}
