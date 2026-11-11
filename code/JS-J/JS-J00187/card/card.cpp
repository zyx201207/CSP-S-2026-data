#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
const int N=5000000005;
const int M=500005;
const int S=20005;
const int T=1005;
const int K=105;
//division
int n,m;
int a[M],cnt[M];
struct node{
    bool flag;
    int pos;
};
node ans[M];
//division
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //division
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) ans[j].flag=0,ans[j].pos=0;
        for(int j=i;j<=n;j++){
            //give a card
            if(!ans[a[j]].flag){
                ans[a[j]].flag=1;
                ans[a[j]].pos=j;
            }
            else for(int k=1;k<=m;k++) if(ans[k].flag && ans[k].pos>ans[a[j]].pos) ans[k].flag=0;
        }
        for(int j=1;j<=m;j++){
            if(ans[j].flag){
                cnt[j]++;
                //if(j==2) cout<<i<<" ";
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    //division
    cout.flush();
    cout<<flush;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
