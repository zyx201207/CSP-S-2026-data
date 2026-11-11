#include<bits/stdc++.h>
using namespace std;
int g[500009];//yuanshu
int s[500009];//dueilie
int w[300009];//ton
int k[300009];//wz
int ans[300009];
int main(){
	memset(ans,0,sizeof ans);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=i;j<=n;j++){
			w[g[j]]++;
			if(w[g[j]]==1){
				s[++q]=g[j];
				k[g[j]]=q;
			}else{
				w[g[j]]=1;
				q=k[g[j]];
				s[q]=g[j];
			}
		}
		if(q>m) continue;
		for(int i=1;i<=q;i++){
			ans[s[i]]++;
		}
		memset(s,0,sizeof s);
		memset(w,0,sizeof w);
		memset(k,0,sizeof k);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}