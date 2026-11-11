#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=0,m;
    cin>>n>>m;
    vector<int> a(n+2);
    vector<long long> ans(m+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int cur=1;cur<=n;cur++){
        vector<int> play(n+2);
        vector<int> place(m+2,n+1);
        vector<bool> vis(m+2);
        int now=0;
        for(int i=cur;i<=n;i++){
            play[++now]=a[i];
            if(place[a[i]]!=n+1){
                now=place[a[i]];
            }
            place[a[i]]=min(place[a[i]],now);
        }
        for(int i=1;i<=now;i++){
            int j=play[i];
            if(vis[j]) continue;
            vis[j]=1;
            ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}