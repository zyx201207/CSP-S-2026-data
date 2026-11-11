#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,x;
struct node{
	int cnt;
	vector<int>a;
}a[5060];
stack<ll>st;
map<ll,int>ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=i;j++){
			a[j].a.push_back(x);
			a[j].cnt++;
		}
	}

	for(int i=1;i<=n;i++){
		map<ll,int>mp;
		for(int j=0;j<a[i].cnt;j++){
			if(mp[a[i].a[0]]!=0){
				ll q=j-mp[a[i].a[j]]-1;
				while(q--)st.pop();
			}
			mp[a[i].a[j]]=j;
			st.push(a[i].a[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
 
