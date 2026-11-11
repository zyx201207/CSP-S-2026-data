#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005],d[300005],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[300005]={0};
		t=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=t-1;k>=b[a[j]];k--){
					b[c[k]]=0;
					t--;
				}
				t++;
			}
			b[a[j]]=t;
			c[t++]=a[j];
		}
		for(int j=1;j<=m;j++) d[j]+=(b[j]?1:0);
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}
