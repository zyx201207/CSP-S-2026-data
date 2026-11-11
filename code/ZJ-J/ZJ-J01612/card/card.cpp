#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++){
		int l=1;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
		    int k=a[j];
		    b[l]=a[j];
		    for(int x=1;x<=l-1;x++){
		    	if(b[x]==b[l]){
		    		l=x;
		    		break;
				}
			}
			l++;
		}
		for(int i=1;i<=l-1;i++) ans[b[i]]++;
	}
	ans[a[n]]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}