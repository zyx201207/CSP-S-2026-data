#include<bits/stdc++.h>
using namespace std;
int t[300001],n,m,b[500001],fu,to[500001];
struct sss{
	bool boo;
	int zb;
}tt[500001];
int main(){
	cin>>n>>m>>b[1];
	for(int i=2;i<=n;i++){
		cin>>b[i];
		if(b[i-1]<=b[i])fu=1;
	}
	if(fu==1){
		for(int i=1;i<=n;i++){
			stack<int>st;
			st.push(b[i]);
			for(int j=i+1;j<=n;j++){
				if(st.top()!=b[j]){
					st.push(b[j]);
				}
			}
			for(int j=1;j<=st.size();j++){
				to[st.top()]++;
				st.pop();
			}
		}
		for(int j=1;j<=m;j++){
			cout<<to[j]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int>st;
		for(int j=1;j<=m;j++)to[i]=0;
		for(int j=i;j<=n;j++){
			if(to[b[j]]==1){
				while(1){
					if(st.top()==b[j]){
						st.pop();
						break;
					}
					st.pop();
				}
			}
			st.push(b[j]);
			to[b[j]]=1;
			for(int j=1;j<=st.size();j++){
				t[st.top()]++;
				st.pop();
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<t[j]<<" ";
	}
	return 0;
}
//1 2 2 3 4 4 5 6
//1 2 1 3
//1 2 3 4
