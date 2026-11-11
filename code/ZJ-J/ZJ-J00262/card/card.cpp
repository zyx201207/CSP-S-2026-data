#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=3e3+10;
int n,m,a[N],b[M][M],c[N],d[M][M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[a[i]][i]++;
	}
	for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++){
          	b[i][j]+=b[i][j-1];
	   	}
    }
    for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
    	    for(int j=1;j<=n;j++){
          		d[i][j]=b[i][j];
	    	}
    	}
		for(int j=1;j<=i-1;j++)d[a[j]][i]--;
		if(d[a[i]][i]%2==1)c[i]++;
	}
	for(int i=1;i<m;i++)cout<<c[i]<<' ';
	cout<<n;
	return 0;
}//Trick||Treat!
