#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using namespace std;
const int N=5e5+5;
int n,m;
ll a[N];
int t[300005];
map<int,int> tt;
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tt.clear();
		q.clear();
		for(int j=i;j<=n;j++){
			tt[a[j]]++;
			if(tt[a[j]]>=2){
				while(!q.empty()&&q.back()!=a[j]){
					q.pop_back();
					t[a[j]]--;
				} 
			}
			q.push_front(a[j]);
			t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" "; 
	}
	return 0;
} 
