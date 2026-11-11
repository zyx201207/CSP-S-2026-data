#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],qs[300005],ans[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int ls=1;ls<=n;ls++){
	memset(b,0,sizeof(b));
	memset(qs,0,sizeof(qs));
	for(int i=ls;i<=n;i++){
		if(b[a[i]]==0){
			b[a[i]]=1;
			qs[a[i]]=i;
		}
		else{
			for(int j=qs[a[i]];j<i;j++){
				b[a[j]]=0;
			}
			b[a[i]]=1;
			qs[a[i]]=i;
		}
	}
	for(int i=ls;i<=n;i++){
		if(b[a[i]]){
			ans[a[i]]++;
			b[a[i]]=0;
		}
	}
}
for(int i=1;i<=m;i++){
	cout<<ans[i]<<" ";
}
}
