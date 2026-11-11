#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int k=1;k<=m;k++){
			b[k]=0;c[k]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]]+1;k<=m;k++){
					if(c[k]==0) break;
					b[c[k]]=0;
					c[k]=0;
					x--;
				}
			}
			else{
				x++;
				b[a[j]]=x;
				c[x]=a[j];
			}
		}
		for(int k=1;k<=x;k++){
			d[c[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
