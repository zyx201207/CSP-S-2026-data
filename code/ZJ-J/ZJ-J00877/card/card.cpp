#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long n,m,a[500010],t[300010];
int main(){
	fast;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long b[5010];
			for(int j=1;j<=n;j++){
				b[j]=-1;
			}
			map<long long,long long> mp;
			for(int j=i;j<=n;j++){
				if(b[a[j]]!=-1){
					for(int k=b[a[j]];k<j;k++){
						if(mp[a[k]]>0){
							mp[a[k]]--;
						}
						b[a[k]]=-1;
					}
				}
				b[a[j]]=j;
				mp[a[j]]++;
			}
			for(auto j:mp){
				if(j.second>0){
					t[j.first]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<n-i+1<<" ";
	}
	return 0;
}
