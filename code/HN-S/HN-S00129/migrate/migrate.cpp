#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
struct P{
	int v,w;
};
int c,t,n,d,a[2000005],b[305][305],f[305][305];
void solve1(){
	memset(f,0x3f,sizeof f);
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)f[i][j]=1,b[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					b[i][j]=1;
				}
				else if(f[i][j]==f[i][k]+f[k][j]){
					b[i][j]+=1;
				}
//				cout<<i<<" "<<j<<" "<<k<<"\t";
//				cout<<f[i][j]<<" "<<f[i][k]+f[k][j]<<"\n";;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(b[i][j]==2)cnt++;
//			cout<<f[i][j]<<" ";
		}
//		cout<<"\n";
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=300)solve1();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
