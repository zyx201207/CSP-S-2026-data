#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],c[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]==2){
				bool fl=0;
				for(int k=i;k<=j;k++){
					if(a[k]==a[j]&&(!b[k]))  fl=1;
					if(fl&&(!b[k])){
						c[a[k]]--;
						b[k]=1;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j])  ans[j]++;
		}
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
