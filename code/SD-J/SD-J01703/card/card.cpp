#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans[100010],nowh;
int now[200010];
int h(int x){
	for (int i=1;i<=nowh;++i){
		if (now[i]==x) return i;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool f=1;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (a[i]<a[i-1] && i!=1) f=0;
	}
	a[n+1]=1e9;
	if (f){
		int anns[100010],hh=1;
		memset(anns,0,sizeof(anns));
		for (int i=2;i<=n+1;i++){
			if (a[i]>a[i-1]) anns[a[i-1]]=i-1;
		}
		for (int i=1;i<=m;++i)
			cout<<anns[i]<<' ';	
		return 0;
	}
	for (int i=1;i<=n;i++){
		nowh=0;
		for (int j=i;j<=n;j++){
			int z=h(a[j]);
			if (z){
				for (int k=z;k<=nowh;k++){
					now[k]=0;
				}
				nowh=z;
				now[nowh]=a[j];
			}	
			else {
				nowh++;
				now[nowh]=a[j];
			}	
		}
		for (int u=1;u<=nowh;u++){
			ans[now[u]]++;
		}
	}
	for (int i=1;i<=m;i++) 
		cout<<ans[i]<<' ';
	return 0;
}
