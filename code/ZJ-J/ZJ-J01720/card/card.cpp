#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	int n,m,i,j;
	cin >> n >> m;
	int a[n],T[m+1]={0};
	for(i=0;i<n;i++)cin>>a[i];
	for(j=0;j<n;j++){
		int t[m+1]={0};
	    stack<int> st;
		for(i=j;i<n;i++){
			st.push(a[i]);
			if(t[a[i]]){
				st.pop();
				while(st.top()!=a[i]){
					if(t[st.top()])t[st.top()]--;
					st.pop();
				}
			}
			else t[a[i]]++;
	    }
		for(i=0;i<=m;i++)T[i]+=t[i];
	}
	for(i=1;i<=m;i++){
		cout << T[i] << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
