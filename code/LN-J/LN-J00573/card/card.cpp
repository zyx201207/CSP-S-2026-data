#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],f2[300005],ans[300005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,false,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==false){
				f[a[j]]=true;
				f2[a[j]]=j;
			}
			else{
				for(int k=f2[a[j]];k<=j;k++){
					f[a[k]]=false;
					f2[a[k]]=0;
				}
				f[a[j]]=true;
				f2[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
