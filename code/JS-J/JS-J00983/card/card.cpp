#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],nowtable[500005],tlen=0,tfa=0,ans[200005];
int main(){
 	freopen("a.in","r",stdin);
	freopen("a.out","W",stdout);	cin>>n>>m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int first=1;first<n;first++){
		tfa=0,tlen=0;
		for(int i=first;i<=n;i++){
			for(int j=1;j<=tlen+1;j++){
				if(a[i]==a[j]){
					tfa=j;
					for(int l=j;l<=tlen+1;l++)nowtable[l]=0;
				}
			}
			if(tfa)tlen=tfa;
			else tlen++;
			nowtable[tlen]=a[i];
		}
		for(int i=1;i<=tlen;i++){
			ans[nowtable[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}