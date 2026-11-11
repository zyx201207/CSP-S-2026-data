#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=5e5+50;

ll n,m;
ll a[maxn];
ll f[maxn],ans[maxn];
stack<ll> st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)f[j]=0;
		
		for(int j=i;j<=n;j++){
			if(f[a[i]!=0]){
			    while(st.top()!=a[i]){
				    f[st.top()]=0;
				    st.pop();
			    }
		    }
		    else{
		    	f[a[i]]=1;
		    	st.push(a[i]);
			}
		}
		while(!st.empty()){
			st.pop();
		}
		for(int j=1;j<=m;j++){
			ans[j]+=f[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
