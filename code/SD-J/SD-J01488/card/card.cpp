#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[5005],subA=1,l[5005],f[5005],c[5005];
deque<int>d,cl;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i>1){
			subA=0;
		}
		l[a[i]]=i;
		if(f[a[i]]==0)f[a[i]]=i;
	}
	if(subA){
		for(int i=1;i<=m;i++)cout<<(l[i]-f[i]+1)<<' ';
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)l[j]=0;
		for(int j=1;j<=m;j++)f[j]=0;
		d=cl;
		for(int j=i;j<=n;j++){
			if(!l[a[j]]){
				l[a[j]]++;
				d.push_back(a[j]);
			}else{
				while(d.back()!=a[j]){
					l[d.back()]--;
					d.pop_back();
				}
			}
		}
		for(auto x:d){
			if(!f[x]){
				f[x]=1;
				c[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
