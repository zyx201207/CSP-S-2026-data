#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N];
int n,m;
ll d[N],s[N];
int mark[N];
map<int,int> mp;
ll ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)mark[j]=0;
			for(int j=i;j<=n;j++){
				s[j]=1;
				if(mark[a[j]]&&s[mark[a[j]]]){
					for(int k=mark[a[j]];k<j;k++)s[k]=0;
				}
				mark[a[j]]=j;
			}
			for(int j=i;j<=n;j++){
				if(s[j])ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}else{
		int r=-1,l=1e7;
		for(int i=n;i>=1;i--){
			if(mp[a[i]]==0){
				mp[a[i]]=i;	
			}else{
				l=min(l,i),r=max(r,mp[a[i]]);
//			d[n]++;
//			d[mp[a[i]]-1]--;
			}
			if(r==-1&&l>n)d[n]++,d[i-1]--;
			else{
				d[n]++,d[r-1]--,d[l-1]++,d[i-1]--;
			} 
		}
		for(int i=n;i>=1;i--)s[i]=s[i+1]+d[i];
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";
		for(int i=1;i<=n;i++)ans[a[i]]+=s[i];
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
}