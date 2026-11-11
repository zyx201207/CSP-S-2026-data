#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],ans[300005],b[300005];//a[i]代表位置为i的数 b[i]表示i这个数的是否在栈里 
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				while(st.top()!=a[j]){
					b[st.top()]=0;
					st.pop();
				}
			}
			else
			st.push(a[j]);
			b[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
