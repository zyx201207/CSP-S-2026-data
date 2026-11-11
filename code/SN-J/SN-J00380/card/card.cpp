#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N];
map<int,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		set<int> st;
		string s;
		for(int j=i;j<=n;j++){
			if(!st.count(a[j])){
				int len=s.size();
				for(int k=0;k<len;k++){
					if(s[i]==char(a[j]+'0')){
						s=s.substr(0,i);
						break;
					}
				}
			}
			else{
				st.insert(a[j]);
				s+=char(a[j]+'0');
			}
		}
		int lenn=s.size();
		mp[lenn]++;
	}
	for(int i=1;i<=m;i++) cout<<mp[i]<<' ';
	return 0;
}
