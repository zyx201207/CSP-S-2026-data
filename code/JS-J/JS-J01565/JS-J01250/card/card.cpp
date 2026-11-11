#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m,a[N+10],cnt[M+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool f[M+10];
		memset(f,0,sizeof(f));
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(!st.empty()){
					if(st.top()==a[j]){
						st.pop();
						break;
					}
					f[st.top()]=0;
					st.pop();
				}
				st.push(a[j]);	
			}else{
				st.push(a[j]);
				f[a[j]]=1;	
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
