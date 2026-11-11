#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],ans[M];
int has[M];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(has,0,sizeof(has));
		for(int j=i;j<=n;j++){
			if(has[a[j]]){
				while(a[st.top()]!=a[j]){
					has[a[st.top()]]--;
					st.pop();
				}
				st.pop();
				st.push(j);
			}else{
				st.push(j);
				has[a[j]]++;
			}
		}
		while(!st.empty())st.pop();
		for(int j=1;j<=m;j++){
			if(has[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
