#include<bits/stdc++.h>
using namespace std;
 stack<long long> st;
long long n,m,a[50005],b[30005],ans[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]==2){
				st.pop();
				while(1){
					st.pop();
					if(st.top()==a[i]){
						break;
					}
				}
				st.pop();
				b[a[i]]=1;
			}
			st.push(a[i]);
		}
		for(int i=1;i<=st.size();i++){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}


