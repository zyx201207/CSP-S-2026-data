#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],t[300005],t1[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=i;j<=n;j++){	
			t[a[j]]++;
			if(t[a[j]]>=2){
				while(st.top()!=a[j]){
					t[st.top()]--;
					st.pop();
				}
				t[a[j]]--;
			}
			else{
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			t1[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t1[i]<<" ";
	}
	return 0;
}
