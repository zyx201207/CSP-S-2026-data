#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],b[300005];
stack<int> st; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(1){
					if(st.top()==a[j]){
						st.pop();
						break;
					}
					b[st.top()]--;
					st.pop();
				}
				b[a[j]]=0;
			}
			b[a[j]]++;
			st.push(a[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
		for(int k=1;k<=m;k++) b[k]=0;
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
