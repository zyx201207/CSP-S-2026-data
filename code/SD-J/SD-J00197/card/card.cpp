#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum[300005],m;
set<int>s ;
deque<int> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s.clear();
		while(!dq.empty()) {
			dq.pop_back();
		}
		for(int j=i;j<=n;j++){
			if(!s.count(a[j])){
				dq.push_back(a[j]);
				s.insert(a[j]);
			}
			else {
				int w=dq.back();
				while(w!=a[j]){
					w=dq.back();
					s.erase(w);
					dq.pop_back();
				}
				dq.push_back(a[j]);
				s.insert(a[j]);
			}
		}
		for(auto it : s){
			sum[it]++;
		}
//		for(int k=1;k<=m;k++){
//			if(s.count(k)) sum[k++];
//		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
}
