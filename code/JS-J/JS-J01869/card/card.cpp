#include<bits/stdc++.h>
using namespace std;
int card[500002];
vector<int> jmp[300002];
int ans[300002];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>card[i];

    for(int i=n;i>=1;i--){
        jmp[card[i]].push_back(i);
    }

    for(int i=1;i<=n;i++){
        if(i>1){
            jmp[card[i-1]].pop_back();
        }
        for(int j=i;j<=n;j++){
            ans[card[j]]++;
            j=jmp[card[j]][0];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}


