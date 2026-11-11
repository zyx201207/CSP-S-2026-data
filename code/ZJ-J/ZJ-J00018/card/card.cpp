#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,top=1;
int a[500005],cs[300005],ans[300005],st[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<300005;j++){
			cs[j]=0,st[j]=0;
		}
		top=1;
		for(int j=i;j<=n;j++){
			if(cs[a[j]]!=0){
				for(int k=top;k>cs[a[j]];k--){
					cs[st[k]]=0;
				}
				top=cs[a[j]];
				top++;
//				cout<<1;
			}else{
				st[top++]=a[j];
				cs[a[j]]=top-1;
//				cout<<0;
			}
		}
		for(int j=1;j<top;j++){
			ans[st[j]]++;
//			cout<<st[j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
