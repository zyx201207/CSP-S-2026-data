#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m,a[N],lst[N],ans[M],to[N],ls[N];
unordered_set<long long>st;
stack<long long>tmp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}for(int i=1;i<=n;++i){
		st.clear();
		while(!tmp.empty())tmp.pop();
		for(int j=i;j<=n;++j){
			if(st.count(a[j])){
				while(!st.empty()&&tmp.top()!=a[j]){
					st.erase(tmp.top());
					tmp.pop();
				}
			}else{
				st.insert(a[j]);
				tmp.push(a[j]);
			}
		}while(!tmp.empty()){
			ans[tmp.top()]++;
			tmp.pop();
		}
	}for(int i=1;i<=m;++i)cout<<ans[i]<<" "; 
	return 0;
}
