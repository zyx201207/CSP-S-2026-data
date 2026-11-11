#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
stack<int>st;
long long a[N],tn[M],anst[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(tn[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					tn[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				tn[a[j]]=1;
			}
		}
		while(!st.empty()){
			int abc=st.top();
			anst[abc]++;
			tn[abc]--;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",anst[i]);
	return 0;
}
