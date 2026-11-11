#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10,M=3e5+10;

int n,m;
int a[N];
map<int,int> mp;
stack<int> st;
int cnt[M];

signed main(){
	freopen("C:\\Users\\stu\\Desktop\\cspj\\down\\card\\card1.in","r",stdin);
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		mp.clear();
		while(!st.empty()) st.pop();
		for(int j=i;j<=n;j++){
			if(mp.count(a[j])&&mp[a[j]]>=1){
				while(!st.empty()&&st.top()!=a[j]){
					mp[st.top()]--;
					st.pop();
				}
			}
			else{
//				mp[st.top()]++;
				st.push(a[j]);
			}
		}
		while(!st.empty()) cnt[st.top()]++,st.pop();
	}
	
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	
	return 0;
}
