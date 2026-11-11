#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5){	
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=i;j<=n;j++){
				if(a[j]==a[j-1]&&j>i){
					b[x]=0;
				}
				b[++x]=a[j];
			}
			for(int j=1;j<=x;j++)ans[b[j]]++;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			int x=0;
			for(int j=i;j<=n;j++){
				for(int k=0;k<=x;k++){
					if(b[k]==a[j]){
						for(int tmp=k;k<=x;k++)b[k]=0;
						x=k-1;
					}
				}
				b[++x]=a[j];
			}
			for(int j=1;j<=x;j++)ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}