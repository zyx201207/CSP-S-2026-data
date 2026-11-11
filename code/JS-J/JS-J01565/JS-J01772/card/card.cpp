#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int vis[N];
int p[N];
int n,m;
int a[N];
int num[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int tot = m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(!vis[a[i]])p[a[i]] = i
        num[a[i]]++;
        vis[a[i]]++; 
    }
    for(int i = n-1;i>=1;i--){
        if(vis[i-1]){
            num[a[i]]+=i-1-p[a[i]];
        }
    }
    num[a[n]] = n;
    for(int i = 1;i<=m;i++){
        cout<<num[i];
    }
    return 0;
}