#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],top,ans[500005];
bool f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		top=0;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(s[top]!=a[j]){
					top--;
				}
			}
			else{
				s[++top]=a[j];
				f[a[j]]=1;
			}
		}
		for(int j=1;j<=top;j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}