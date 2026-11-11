#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],t=0,c[1000005],d[1000005],e[1000005];
int f(int b){
	for(int i=1;i<=t;i++){
		if(b==a[i]){
			return i;
		}
	}return -1;
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(j)==-1){
				a[++t]=j;
			}else{
				for(int i=1;i<=f(j);i++){
					c[i]=a[i];
				}
				t=f(j);
				memset(a,0,sizeof(a));
				for(int i=1;i<=f(j);i++){
					a[i]=c[i];
				}
				memset(c,0,sizeof(c));
				a[++t]=j;
			}
		}
		for(int i=1;i<=n;i++){
			if(e[a[i]]==0){
				e[a[i]]=1;
				d[a[i]]++;
			}
		}
		memset(e,0,sizeof(e));
		for(int i=1;i<=m;i++){
			cout<<d[i]<<' ';
		}
		memset(a,0,sizeof(a));

	}
	return 0;
}
