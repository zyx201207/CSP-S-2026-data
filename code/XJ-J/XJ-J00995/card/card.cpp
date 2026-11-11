#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],S[500005],top,cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		//cout<<top<<" ";
		memset(S,0,sizeof(S));
		top=0;
		for(int j=i;j<=n;j++){
			for(int k=top;k>=1;k--){
				if(S[k]==a[j]){
					top=k-1;
					break;
				}
			}
			S[++top]=a[j];	
		}
		for(int k=1;k<=top;k++){
			cnt[S[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}