#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],rd[500005],ans[300005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=n;
		for(int j=1;j<=n;j++) t[j]=a[j];
		for(int j=i;j<=x;j++){
			if(!rd[t[j]])
				rd[t[j]]=j;
			else{
				for(int s=j;s<=x;s++){
					t[s-(j-rd[t[j]])]=t[s];
				}rd[t[j]]=0;x-=(j-rd[t[j]]);
			}
		}
		for(int j=1;j<=x;j++) ans[t[j]]++;
		for(int j=1;j<=m;j++) rd[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i];
	return 0;
} 
