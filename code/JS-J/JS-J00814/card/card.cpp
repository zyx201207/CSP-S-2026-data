#include<bits/stdc++.h>
using namespace std;
int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> a(n),ans(m+1,0),l(m+1,-1);

    for(int i=0;i<n;i++) cin>>a[i];
    reverse(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(l[a[i]]==-1) l[a[i]]=i;
        int s=i;
        while(s>=0){
            int cur=a[s];
            ans[cur]++;
            s=l[cur]-1;
        }
    }

    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
