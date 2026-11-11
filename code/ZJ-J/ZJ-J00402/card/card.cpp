#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],cnt[N],vis[N],f=1,f2=1,s[N],sum[N];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
		if(cnt[a[i]]==1){
			f2=0;
		}
		cnt[a[i]]=1;
	}
	if(f2==1){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++) cnt[i]=0;
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	if(n<=2000){
		for(int k=1;k<=n;k++){
			for(int i=k;i<=n;i++){
				if(mp[a[i]]>0){
					for(int j=mp[a[i]]+1;j<=i;j++){
						b[j]=0;
						if(mp[a[j]]==mp[a[i]]){
							continue;
						}
						mp[a[j]]=0;
					}
					mp[a[i]]=i;
				}else{
					mp[a[i]]=i;
					b[i]=a[i];
					
				}
			}
			for(int j=1;j<=n;j++){
				if(b[j]>0){
					
					cnt[b[j]]++;
				}
				b[j]=0;
				mp[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	cnt[a[n]]=n;
	for(int i=1;i<=n;i++){
		if(mp[a[i]]==0){
			mp[a[i]]=i;
		}
	}
	for(int i=n;i>=1;i--){
		if(mp[a[i]]==n) continue;
		s[i-1]+=(mp[a[i]]);
		s[mp[a[i]]-1]-=mp[a[i]];
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			sum[i]=n;
			continue;
		}
		sum[i]=(n-i+1)+s[i]+s[i-1];
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
  
