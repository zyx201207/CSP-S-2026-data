#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int b[500005];
bool f;
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			f=0;
			for(int k=i;k<j;k++){
				if(b[j]==b[k]) f=1;
				if(f==1) b[k]=0;
			}
		}
		for(int j=i;j<=n;j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

