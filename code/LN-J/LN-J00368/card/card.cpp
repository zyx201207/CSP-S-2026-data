#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int M = 3e5+5;
int a[N];
int cnt[M];

bool find(int k,stack<int> st){
	while(st.size()){
		int t = st.top();
		if(t==k){
			return true;
		}
		st.pop();
	}
	return false;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int> st;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(find(a[j],st)){
				while(true){
					int tmp = st.top();
					if(tmp!=a[j]){
						st.pop();
					}else{
						break;
					}
				}
			}else{
				st.push(a[j]);
			}
		}
		while(st.size()){
			int t = st.top();
			cnt[t]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
