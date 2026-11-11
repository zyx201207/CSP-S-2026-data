#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],c[N],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int q=1;q<=n;q++){
		memset(c,0,sizeof c);
		int top=0;
		for(int i=q;i<=n;i++){
			int b=-1;
			for(int j=1;j<=top;j++){
				if(c[j]==a[i]){
					b=i;
					break;
				}
			}
			if(b!=-1){
				top=b-1;
				for(int j=b+1;j<=top;j++)	c[j]=0;
			}
			else c[++top]=a[i];
		}
		for(int i=1;i<=top;i++)	ans[c[i]]++;
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<' ';
	return 0;
}
