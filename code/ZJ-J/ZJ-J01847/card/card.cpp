#include<bits/stdc++.h>
using namespace std;
const int M=300005;
int n,m,a[500005],tj[M],ans[M];
stack<int> s;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int t=1;t<=n;t++){
		memset(tj,0,sizeof(tj));
		for(int i=t;i<=n;i++){
			if(tj[a[i]]!=0){
				while(s.top()!=a[i] and !s.empty()){
					tj[s.top()]--;
					s.pop();
				}
			}else{
				tj[a[i]]++;
				s.push(a[i]);
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
