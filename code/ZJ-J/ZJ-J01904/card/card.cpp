#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		r=0;
		int b[300005]={},c[300005]={};
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0){
				int l=b[a[j]]+1;
				for(int k=l;k<=r;k++)b[c[k]]=0;
				r=l-1;
			}
			else{
				r++;
				b[a[j]]=r;
				c[r]=a[j];
			}
		}
		for(int j=1;j<=m;j++)if(b[a[j]])ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
