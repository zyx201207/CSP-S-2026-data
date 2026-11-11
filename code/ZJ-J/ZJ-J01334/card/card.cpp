#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		vector<long long> b(n+10,0);
		long long st[500010];
		long long k=0;
		for(long long j=i;j<=n;j++){
			if(!b[a[j]]){
				st[++k]=a[j];
				b[a[j]]=j;
			}
			else{
				while(st[k]!=b[a[j]]){
					b[st[k]]=0;
					st[k]=0;
					k--;
				}
				st[k]=0;
				k--;
				b[a[j]]=j;
				st[++k]=a[j];
			}
		}
		while(k){
			ans[st[k]]++;
			st[k]=0;
			k--;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}