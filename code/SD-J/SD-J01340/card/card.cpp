#include<bits/stdc++.h>
using namespace std;
int n,k,a[500020],b[300020],m[300020],id[300020],ans[300020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=i;j<=n;j++){
			c++;
			if(m[a[j]]==0) {b[c]=a[j];m[a[j]]=1;id[a[j]]=c;}
			else{
				for(int p=id[a[j]]+1;p<=c;p++){
					m[b[p]]=0;id[b[p]]=0;
				}
				c=id[a[j]];
			}
		}
		for(int j=1;j<=c;j++){
			ans[b[j]]++;
		}
		for(int j=1;j<=k;j++){
			b[j]=0;m[j]=0;id[j]=0;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
