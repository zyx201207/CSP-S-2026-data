#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[50005],k;
bool find(int x){
	for(int i=1;i<=k;i++){
		if(b[i]==x) return 1;
	}
	return 0;
}
int num(int x){
	for(int i=1;i<=k;i++){
		if(b[i]==x) return i;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=0;memset(b,-1,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!find(a[j])) b[++k]=a[j];
			else{
				int v=k;
				for(int l=num(a[j]);l<=k;l++){
					b[i]=-1;v--;
				}	
				k=v;
				b[++k]=a[j];
			}
		}
		for(int j=1;j<=k;j++){
			ans[b[j]]++;
		}
}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
