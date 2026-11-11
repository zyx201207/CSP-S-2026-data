#include<iostream>
using namespace std;//朕宁拼一死，***安敢一战！
int n,m,cnt[300005],a[500005],lst[300005];bool ok=1;
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i],ok&=(a[i]>=a[i-1]),lst[a[i]]=i;
	if(m<=2){
		for(int i=1;i<=n;i++)cnt[a[i]]++,cnt[a[n]]+=(a[n]!=a[i]);
	}else if(ok){
		for(int i=1;i<=n;i++)for(int j=a[i];j<=a[n];j++)cnt[j]++;
	}else{
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
			int nxt=lst[a[i]];
			while(nxt<n){
				cnt[a[nxt+1]]++,nxt=lst[a[nxt+1]];
			}
		}
	}for(int i=1;i<m;i++)cout<<cnt[i]<<' ';cout<<cnt[m];
	return 0;}
