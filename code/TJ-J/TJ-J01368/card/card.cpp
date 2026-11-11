#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		int t[500010]={0};
		for(int j=i;j<=n;j++){
			if(!st.empty()&&t[a[j]]!=0){
				while(!st.empty()&&st.top()!=a[j]){
					t[st.top()]--;
					st.pop();
				}
			}else{
				st.push(a[j]);
				t[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=0){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}//2
