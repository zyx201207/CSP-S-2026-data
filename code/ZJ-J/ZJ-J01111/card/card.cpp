#include<bits/stdc++.h>
using namespace std;
long long n,m,w,s,a[1000010],ans[1000010],ff[1000010],zh[1000010],fff[1000010];
vector <int> f[1000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		f[a[i]].push_back(i);
	}
	if(n>=200000){
		for(int i=1;i<=m;i++){
			int x=f[i][f[i].size()-1]-f[i][0]+1;
			s+=x;
			cout<<s<<" ";
		}
		return 0;
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++) ff[i]=0;
		for(int i=1;i<=m;i++) fff[i]=0;
		for(int i=l;i<=n;i++){
			long long t=i,w=f[a[i]][f[a[i]].size()-1];
			if(t>=w) continue;
			ff[t+1]--,ff[w]++;
			i=w;
		}
		for(int i=l+1;i<=n;i++){
			ff[i]=ff[i]+ff[i-1];
		}
		for(int i=l;i<=n;i++){
			if(fff[a[i]]==0&&ff[i]>=0){
				fff[a[i]]=1;ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}