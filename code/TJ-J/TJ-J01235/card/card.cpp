#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
ll a[N],mp[300010],ret[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int>st;
    for(int i=1;i<=n;i++){
        memset(mp,0,sizeof(mp));
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==0){
                st.push(a[j]);
                mp[a[j]]++;
            }
            else{
                while(st.top()!=a[j]){
                	mp[st.top()]--;
					st.pop();
				}
            }
        }
        while(!st.empty()){
            ret[st.top()]++; 
            st.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<ret[i]<<' ';
    return 0;
}
