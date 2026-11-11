#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005];
int s[500005],top;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int t=1;
	while(t<=n){
		top=0;
		for(int i=t;i<=n;i++){
			s[++top]=a[i];
			for(int j=1;j<top;j++){
				if(s[j]==s[top]){
					top=j;
					break;
				}
			}
		}for(int i=1;i<=top;i++){
			ans[s[i]]++;
		}t++;
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
