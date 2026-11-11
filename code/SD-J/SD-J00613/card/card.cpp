#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005],b[300005];
int s[500005],top=0;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(b[a[j]]==1){
					b[s[top]]=0;
					top--;
				}
			}
			s[++top]=a[j];
			b[a[j]]=1;
		}
		for(int j=1;j<=top;j++){
			cnt[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
