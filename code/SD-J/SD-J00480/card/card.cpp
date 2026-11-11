#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int lst[N];
int cnt[N];
int ans[N];
bool taska=1;
//vector<int> q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i-1]<=a[i])){
			taska=0;
		}
//		lst[a[i]]=i;
	}
	if(taska){
		for(int i=1;i<=n;i++){
			lst[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<lst[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){//n次游戏 
//		q.clear();
		for(int j=i;j<=n;j++){
			cnt[a[j]]=0;
			lst[a[j]]=0;
		}
		for(int j=i;j<=n;j++){//每局游戏 
			
			if(lst[a[j]]!=0&&cnt[a[j]]>=1){
				for(int k=lst[a[j]];k<=j-1;k++){
					if(cnt[a[k]]>=1) --cnt[a[k]];
				}
//				for(int k=i;k<=j-1;k++){
//					if(a[k]==a[j]){
//						if(cnt[a[k]]>=1) --cnt[a[k]];
//					}
//				}
				
			}
			lst[a[j]]=j;
			++cnt[a[j]];
//					for(int j=i;j<=n;j++) cout<<cnt[a[j]]<<" ";
//		cout<<"\n";
//			flag[a[j]]=1;
//			q.emplace_back(a[j]);
		}
//		cout<<i<<":";
//		for(int j=i;j<=n;j++) cout<<cnt[a[j]]<<" ";
//		cout<<"\n";
		for(auto j=i;j<=n;j++){
			if(cnt[a[j]]>=1ll){
				
				++ans[a[j]];
				cnt[a[j]]=0;
//				cout<<a[j]<<" ";
			}
			
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
