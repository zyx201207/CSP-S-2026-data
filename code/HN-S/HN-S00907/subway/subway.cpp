#include<bits/stdc++.h>
using namespace std;

int su,n,m,d,q,s,t=0,minn=0x3f3f3f3f;
int yc[1005],yc2[1005];
int a[1005],b[25][1005],c[25][1005];

void f(int z,int x,int y){
	minn=min(minn,t);
	for (int i=1;i<=n;i++){
		if (b[i][x] >= i && i != z){
			t+=c[i][x];
			f(i,x,y);
			t-=c[i][x];
		}
	}
	for (int i=1;i<=m;i++){
		if (b[z][i] >= i && i != x){
			t+=c[z][i];
			f(z,i,y);
			t-=c[z][i];
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>su>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		for (int j=1;j<=x;j++){
			cin>>yc[j]>>yc2[j];
		}
		for (int j=1;j<=x;j++){
			b[i][yc[j]]=1;
			c[i][yc[j]]=yc2[j];
		}
	}
	
	for (int i=1;i<=q;i++){
		int zz=0;
		t=0;
		minn=0x3f3f3f3f;
		int x_,y_;
		cin>>x_>>y_;
		for (int j=1;j<=n;j++){
			if (b[j][x_] != 0){
				zz=j;
				j=n;
			}
		}
		f(zz,x_,y_);
		cout<<a[x_]+a[y_]+minn<<endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
