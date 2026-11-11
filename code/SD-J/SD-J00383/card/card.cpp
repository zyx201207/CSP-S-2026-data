#include <bits/stdc++.h>

using namespace std;
int n,m,a[500010],ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int c[300010];
		for (int q=1;q<=m;q++){
			c[q]=0;
		}
		for (int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=1;
			}
			else{
				for (int q=1;q<=m;q++){
					c[q]=0;
				}
				c[a[j]]=1;
			}
		}
		for (int i=1;i<=m;i++){
			ans[i]+=c[i]; 
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
