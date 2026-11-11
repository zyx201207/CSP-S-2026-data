#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool f=1;
int ans[300010];
int b[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1])f=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])cout<<i<<" ";
		}
		return 0;
	} 
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool is=0;
			for(int k=1;k<=m;k++){
				if(b[k]==a[j]){
					is=1;
					for(int l=k+1;l<=m;l++)b[l]=0;
					cnt=k;
				}
			}
			if(is==0)b[++cnt]=a[j];
		}
		for(int x=1;x<=m;x++){
			if(b[x]!=0)ans[b[x]]++;
		}		
		for(int x=1;x<=m;x++)b[x]=0;
		cnt=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
