#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,f[N],s[5010][5010],a[N],ans[5010],cnt[5010];
vector<pair<int,int> >g;
long long tjj=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[j][i]=s[j][i-1];
		}
		cin>>a[i];
		if(f[a[i]]==0)f[a[i]]=i;
		s[a[i]][i]++;
	}
	for(int i=1;i<=n;i++){
		int tj[5010],tjj[5010];
		memset(tjj,0,sizeof tjj);
		for(int c=1;c<=m;c++){
			tj[c]=s[c][n]-s[c][i-1];
		}
		for(int j=i;j<=n;j++){
			if(f[a[j]]<i||f[a[j]]>j)f[a[j]]=j;
			else{
				for(int c=1;c<=m;c++){
					tj[c]-=s[c][j-1]-s[c][f[a[j]]-1];
				}
				for(int c=1;c<=m;c++){
					tjj+=s[c][j-1]-s[c][f[a[j]]-1];
				}
			}
			f[a[j]]=j;
		}
		for(int c=1;c<=m;c++){
			if(tj[c]>0)ans[c]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;