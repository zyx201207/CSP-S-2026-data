#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int ans[M];
bool t[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(!t[a[i]]){
				st.push(a[i]);
				t[a[i]]=true;
			}
			else{
				while(!st.empty()&&st.top()!=a[i]) t[st.top()]=false,st.pop();
			}
		}
		while(!st.empty()) ans[st.top()]++,st.pop();
		memset(t,false,sizeof t);
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
