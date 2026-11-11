#include<bits/stdc++.h>
using namespace std;
int n,m,f[500005],a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	for(int i =1;i<=m;i++){
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++){
			for(int k=j;k<=m;k++){
				if(a[k]==a[i]){
					f[j]=max(f[j-1]+1,f[j]);
				}else{
					f[j]=max(f[j-1],f[j]);
				}
			}
		}
		cout<<f[n]<<" ";
	}
	return 0;
}
