#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m;
long long a[N];
long long b[N];
long long cnt[N];
long long ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		memset(b,0,sizeof(b));
		long long x=1;
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
			b[x]=a[i];
			x++;
			if(cnt[a[i]]==2){
				for(int j=1;j<=x-1;j++){
					if(b[j]==a[i]){
						x=i;
						break;
					}
				}
				cnt[a[i]]--;
			}
		}
		for(int i=1;i<=x;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
