#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int t[300001];
int t2[300001];
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
//			cout<<j<<endl;
			t[a[j]]++;
			if(t[a[j]]>1){
				while(st.top()!=a[j]){
					t[st.top()]--;
					st.pop();
					
				}
//				cout<<st.top()<<endl;
				t[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
		}
		while(!st.empty()){
//			cout<<st.top()<<" ";
			t2[st.top()]++;
			st.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<t2[i]<<" ";
	}
}//AKCSPJJJJJJJ!!!!!!!!!!!!!!!!!!!!AND CSPSSSSSSSSSSSSS!!!!!!!!!!
