#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
long long n,m;
long long a[N],dc[N],c[N],d[N],w[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dc[a[j]]=0;
			d[j]=0;
			w[a[j]]=0;
		}
		for(int j=i,x=1;j<=n;j++,x++){
			if(dc[a[j]]==0){
				d[x]=a[j];
				c[a[j]]+=1;
				dc[a[j]]=1;
				w[a[j]]=x;
			}else{
				for(int k=w[a[j]]+1;k<=j-1;k++){
					c[d[k]]-=1;
					dc[d[k]]=0;
					d[k]=0;
				}	
				x=w[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
