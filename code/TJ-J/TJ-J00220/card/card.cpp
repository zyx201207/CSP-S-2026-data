#include <bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt[N];
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
        pair<bool,int> has[N];
        int table[N];
        int ed;
        for(int j=i;j<=n;j++){
            memset(has,0,sizeof has);
            memset(table,0,sizeof table);
            ed=1;
            if(!has[a[j]].first) table[ed]=a[j],has[a[j]].second=ed,ed++;
            else {
                for(int k=has[a[j]].second+1;k<=ed;k++) has[a[k]]=make_pair(0,0);
                ed=has[a[j]].second;
            }
        }
        for(int j=1;j<=m;j++){
            cnt[j]+=has[a[j]].first;
        }
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
