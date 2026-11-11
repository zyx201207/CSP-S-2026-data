#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum;
map<long long,long long> mp1,mp2,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum++;
			mp2[sum]=a[j];
			if(mp1.find(a[j])!=mp1.end() && mp1[a[j]]!=0){
				sum=mp1[a[j]];
			}else mp1[a[j]]=j;
		}
		for(int j=1;j<=sum;j++){
			cnt[mp2[j]]++;
		}
		sum=0;
		mp1.clear();
		mp2.clear();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
