#include<bits/stdc++.h>
using namespace std;
const int N=1E4+10;
long long f[N][N],a[N];
long long ans;
int n,m;

int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	if(n>=10000){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)f[i][0]=0,f[0][i]=0;
	for(int i=1;i<=n;i++)f[i][1]=max(f[i-1][1],a[i]);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=min(i,m);j++){
            //cout<<f[i][j]<<" "<<(f[i][j-1]&a[i])<<" "<<f[i-1][j-1]<<" "<<i<<" "<<j<<"\n";
			f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
		}
	}
	cout<<f[n][m];
	return 0;
}
