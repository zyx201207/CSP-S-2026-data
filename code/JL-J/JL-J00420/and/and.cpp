#include<bits/stdc++.h>
using namespace std;
int k[1000000];
    int n,m;
    int ans=0;
    int j=0;
    int p[1000000];
void dfs(int x,int s){

    if(s==m){
            int o=p[1];
            for(int i=2;i<=j;i++){
                o&=p[i];
            }
        ans=max(ans,o);
    }
    for(int i=x+1;i<n;i++){
            j++;
            p[j]=k[i];
        dfs(i,s++);
        j--;
    }
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;

    for(int i=0;i<n;i++)
    cin >> k[i];
    for(int i=0;i<n;i++){
    dfs(i,0);

    }
    cout << ans;
    return 0;
}

