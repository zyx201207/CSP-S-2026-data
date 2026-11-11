#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],ans[500500],b[300500],T;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	T=n;
	while(T){
		T--;
		long long t;
		stack<long long> st;
		for(int i = (n-T);i <= n;i++){
			st.push(a[i]);
			b[a[i]]++;
			if(b[a[i]]==2){
				t=a[i];
				st.pop();
				b[t]--;
				while(st.top()!=t){
					b[st.top()]--;
					st.pop();
				}
			}
		}
		for(int i = 1;i <= m;i++){
			if(b[i]>0){
				ans[i]++;
				b[i]=0;
			}
		}
	}
	for(int i = 1;i <= m;i++) cout<<ans[i]<<' ';
	return 0;
}
