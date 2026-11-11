#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],f[N],cnt[N],cnt2[N];
stack<int> st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=1;
	}
	for(int i=n;i>=1;i--){
		if(f[a[i]]==0){
			st.push(a[i]);
			f[a[i]]=1;
			cnt[a[i]]++;
		}
		else{
			if(st.size()!=0){
				st.pop();
				cnt[st.top()]--;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
