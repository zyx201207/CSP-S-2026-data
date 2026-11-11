#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],pai[500005];
bool t[500005];
map<int,int> mp;
set<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int cnt=1;
	
	for(int i=1;i<=n;i++){
		cin >> pai[i];
	}
	
	int nn=n;
	while(nn--){
		int p=1;
		
		for(int i=cnt;i<=n;i++){
			arr[i-cnt+1]=pai[i];
			st.insert(pai[i]);
			if(t[pai[i]]){
				int r=i-cnt;
				while(r>0){
					t[arr[r]]=0;
					st.erase(arr[r]);
					if(arr[r]==pai[i]) break;
					r--;
				}
				st.insert(pai[i]);
				p=i-cnt+1;	
			}
			t[pai[i]]++;
		}
		
		for(auto x:st){
			mp[x]++;
		}
		
		cnt++;
		memset(arr,0,sizeof(arr));
		memset(t,0,sizeof(t));
		st.clear();
	}
	
	for(int i=1;i<=m;i++){
		cout << mp[i]<<" ";
	}
	
	
	return 0;
} 
