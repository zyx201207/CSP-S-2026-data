#include<bits/stdc++.h>
#define dbg(x) cerr<<"In Line "<<__LINE__<<" , "<<#x<<" = "<<x<<'\n';
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;cin>>n>>m;
	vector<int> a(n+1);
	vector<int> ans(m+1,0); 
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int turn=1;turn<=n;turn++){
		vector<int> st(n+1);int cnt=0;
		for(int i=turn;i<=n;i++){
			for(int j=cnt;j>=1;j--){
				if(st[j]==a[i]){
					cnt=j-1;
					break;
				}
			}
			st[++cnt]=a[i];
		}
		for(int i=1;i<=cnt;i++){
			ans[st[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
