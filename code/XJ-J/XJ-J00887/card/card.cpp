#include<bits/stdc++.h>
using namespace std;
int n,m,f[300005],g[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	for(int i=1 ; i<=n ; i++){
		stack <int> st;
		memset(f,0,sizeof(f));
		for(int j=i ; j<=n ; j++){
			if(f[a[j]]==0){
			    st.push(a[j]);
				f[a[j]]=1;
			}else{
				int l=st.size();
				while(st.top()!=a[l]){
					f[a[l]]=0;
					l--;
					st.pop();
				}
			}
		}
		for(int j=1 ; j<=m ; j++){
			if(f[j]==1){
				g[j]++;
			}
		}
	}
	for(int i=1 ; i<=m ; i++){
		cout << g[i] << " ";
	}
	return 0;
}
