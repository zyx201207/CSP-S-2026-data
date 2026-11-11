#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005],b[500005],c[300005],ans[300005],top;
int main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		memset(c,0,sizeof(c));
		for(int j=n-i+1;j<=n;j++){
			if(c[a[j]]==0){
				b[++top]=a[j];
				c[a[j]]=top;
			}else{
				while(top>c[a[j]]){
					c[b[top]]=0;
					top--;
				}
			}
		} 
		for(int i=1;i<=m;i++){
			if(c[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return  0;
}
