#include<bits/stdc++.h>
using namespace std;
long long n,m,f[500005],a[500005],s[300005],lnow,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]!=0){
				for(int k=f[a[j]];k<j;k++)f[a[k]]=0;
			}
			f[a[j]]=j;
		}
		cnt=0;
		for(int j=1;j<=m;j++){
			if(f[j]!=0)s[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}