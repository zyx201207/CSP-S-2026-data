#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<int> ans(m+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        
        unordered_map<int,int> mp,press;
        vector<int> cards;
        for(int j=1;j<=m;j++) mp[j]=-1,press[j]=0;
        for(int j=i;j<=n;j++){
            if(mp[a[j]]==-1) mp[a[j]]=cards.size();
            else if(cards[mp[a[j]]]==a[j])cards.erase(cards.begin()+mp[a[j]],cards.end());
            cards.push_back(a[j]);
        }
        for(auto x:cards){
//        	cout<<x<<" ";
            if(press[x]==0){
                ans[x]++;
                press[x]=1;
            }
        }
//        cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    
	return 0;
}
