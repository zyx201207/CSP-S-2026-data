#include<bits/stdc++.h>
using namespace std;
int a[50];
int b[2000][2000];
int t[2000][2000];
int c[100005][4];
int bj[50];
int jizun[2000][4];
int c1;
int n;
int m;
int d;
int q;
long long k;
long long minn;
void f(int j,int z){
	if(j == z){
		minn = min(k,minn);
		return ;
	}
	for(int i = 1;i<=m;i++){
		if(b[j][i] == 1 && bj[i] == 0){
			bj[i] = 1;
			k = k+t[j][i]+t[i][i];
			f(i,z);
			k = k-t[j][i]-t[i][i];
			bj[i] = 0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	int x;
	for(int i = 1;i<=n;i++){
		cin>>x;
		for(int j = 1;j<=x;j++){
			cin>>jizun[j][1]>>jizun[j][2];
			for(int y = 1;y<=j;y++){
				if(jizun[y][1]!=jizun[j][1]){
					b[jizun[y][1]][jizun[j][1]] = 1;
				}
				t[jizun[y][1]][jizun[j][1]] = jizun[j][2];
			}
		}
	}
	for(int i = 1;i<=q;i++){
		cin>>c[i][1];
		cin>>c[i][2];
		minn = 1000000000;
		k = a[c[i][1]]+a[c[i][2]];
		for(int j = 1;j<=m;j++){
			if(b[c[i][1]][j] == 1){
				bj[j] = 1;
				bj[c[i][1]] = 1;
				k = k+t[c[i][1]][c[i][1]]+t[c[i][1]][j];
				f(j,c[i][2]);
				k = k-t[c[i][1]][c[i][1]]-t[c[i][1]][j];
				bj[c[i][1]] = 0;
				bj[j] = 0;
			}
		}
		cout<<minn<<"\n";
	}
} 
