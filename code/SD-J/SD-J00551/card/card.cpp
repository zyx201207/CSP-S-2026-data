#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[N],k,c[N];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(f[a[i]]){
				while(b[k]!=a[i]&&k>0){
					f[b[k]]=0;
					b[k]=0;
					k--;
				}
			}else{
				b[++k]=a[i];
				f[a[i]]=1;
			}
		}
		for(int i=1;i<=k;i++){
			c[b[i]]++;
		}
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		k=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}

