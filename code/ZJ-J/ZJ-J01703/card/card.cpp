#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500007;
const int M=300007;
int n,m,a[N],cnt[M],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		memset(cnt,0,sizeof(cnt));
		for(int i=k;i<=n;i++){
			if(cnt[a[i]]>0){
				for(int j=k;j<i;j++){
					if(a[j]==a[i]&&cnt[a[j]]){
						for(int x=j;x<i;x++)
							if(cnt[a[x]]) cnt[a[x]]--;
						break;
					}
				}
			}
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]>0) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}