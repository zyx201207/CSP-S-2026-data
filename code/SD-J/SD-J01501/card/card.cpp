#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
int n,m;
int a[500005],t[300005],ans[300005];
vector<int> v;
bool check_a(){
	for(int i = 2;i <= n;i++){
		if(a[i - 1] > a[i])return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(check_a()){
		stack<int> st;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(st.empty()){
					st.push(a[j]);
					continue;
				}
				if(st.top() == a[j]){
					st.pop();
				}
				else st.push(a[j]);
			}
			while(!st.empty()){
				ans[st.top()]++;
				st.pop();
			}
		}
		for(int i = 1;i <= m;i++){
		 	cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		v.clear();
		memset(t,0,sizeof t);
		for(int j = i;j <= n;j++){
			if(t[a[j]]){
				int len = v.size(),pos;
				for(int k = 0;k < len;k++){
					if(v[k] == a[j]){
						pos = k;
						break;
					}
				}
				for(int k = pos;k < len;k++){
					t[v[k]] = 0;
				}
				v.erase(v.begin() + pos,v.end());
			}
			v.push_back(a[j]);
			t[a[j]] = 1;
		}
		for(int k = 0;k < v.size();k++){
			ans[v[k]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
