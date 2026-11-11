#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[500005],t[300005],bl=0;
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				for(int k=t[a[j]];k<j;k++){
					t[b[k]]=0;
					b[k]=0;
					bl--;
				}
			}
			b[++bl]=a[j];
		}
		for(int j=1;j<=bl;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
