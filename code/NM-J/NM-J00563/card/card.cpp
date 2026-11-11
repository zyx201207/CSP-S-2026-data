#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
bool flag=1;
int a[500010],ans[300010];
stack<int> st,r;
map<int,int> mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
    for(int i=1;i<=n;i++){
    	st=r;
    	for(int j=i;j<=n;j++){
    		if(!st.empty()&&mp[a[j]]>=1){
    			while(!st.empty()&&st.top()!=a[j]){
    				mp[st.top()]--;
					st.pop();
				}
				if(!st.empty())st.pop();
			}
			else{
				st.push(a[j]);
    			mp[a[j]]++;
			}

		}
		for(int j=1;j<=m;j++){
			ans[a[j]]+=mp[a[j]];
			mp[a[j]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
