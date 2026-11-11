#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M],f[M],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				b[a[j]]++;
				f[a[j]]=1;
				c[a[j]]=j;
			}else{
				for(int t=c[a[j]];t<j;t++){
					f[a[t]]=0;
					b[a[t]]--;
				}
				f[a[j]]=1;
				b[a[j]]++;
				c[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
