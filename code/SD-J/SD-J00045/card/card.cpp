#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],v[N];
bool flag=0;
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=1;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]) ans[a[n]]++;
			else ans[1]++,ans[2]++;
		}
		cout<<ans[1]<<" "<<ans[2];
		return 0;
	}
	if(flag==0){
		a[n+1]=-1234567890;
		for(int i=n;i>=1;i--)
			if(a[i]!=a[i+1]) ans[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				while(st.top()!=a[j]){
					v[st.top()]=0;
					st.pop();
				}
			}
			else {
				v[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
//			cout<<i<<" "<<st.top()<<endl;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
