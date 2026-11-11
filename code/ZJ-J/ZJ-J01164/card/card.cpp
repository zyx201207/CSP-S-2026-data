#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005],ans[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(b[a[i]]==0){
				t++;
				c[t]=a[i];
				b[a[i]]=t;
			}	
			else{
				t=b[a[i]];
				c[t]=a[i];
			}
		}
		for(int i=1;i<=t;i++){
			ans[c[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}