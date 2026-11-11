#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],f[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h=1;
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				h=f[a[j]];
			}f[a[j]]=h;
			b[h]=a[j];h++;
		}
		for(int j=1;j<h;j++){
			c[b[j]]++;//cout<<b[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
