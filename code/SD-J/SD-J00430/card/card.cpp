#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];	
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=1;j<=n;j++){
			b[j]=0;
			c[j]=0;
		} 
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				l++;
				c[l]=a[j];
				b[a[j]]=l;
			} 
			else {
				l=b[a[j]];
				for(int p=l+1;p<=n;p++) b[c[p]]=0;
			}
		}
		for(int j=1;j<=l;j++) d[c[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
