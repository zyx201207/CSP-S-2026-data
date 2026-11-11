#include<bits/stdc++.h>
using namespace std;
typedef long long love;
const int N=1e6+10;
//love cly;
int n,m,a[N],t[N];
struct Node{
    int id;
    bool out=0;
}dp[300100]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        vector <int> v(N);
        for(int j=i;j<=n;j++){
            if(dp[a[j]].out==1) v.erase(v.begin()+dp[a[j]].id,v.end());
            v.push_back(a[j]);
            dp[a[j]].id=j;dp[a[j]].out=1;
        }
        for(int k=1;k<=v.size();k++){
                //cout<<v[k]<<" ";
            t[v[k]]++;
        }//cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<t[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
