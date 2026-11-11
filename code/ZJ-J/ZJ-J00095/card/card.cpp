#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
int n,m,a[500005],w[500005],now,f[500005],ans[500005];
bool check(){
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n>=30000 && check()){
		for(int i=n;i>=1;i--){
			ans[a[i]]=max(ans[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		now=1;
		for(int j=i;j<=n;j++){
			if(w[a[j]]==0){
				w[a[j]]=now;
				f[now]=a[j];
				now++;
			}
			else{
				for(int k=w[a[j]]+1;k<=now;k++){
					w[f[k]]=0;
					f[k]=0;
				}
				now=w[a[j]]+1;
			}
		}
		for(int j=1;j<=now;j++){
			ans[f[j]]++;
			w[f[j]]=0;
			f[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}