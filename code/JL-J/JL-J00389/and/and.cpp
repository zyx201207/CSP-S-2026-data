#include <bits/stdc++.h>
using namespace std;
int ans=1e9;
int a[200005];
string h[200005];
void dfs(int u,int y){
    while(y>0){
        h[u]+=y%2+'0';
        y/=2;
    }
    return ;
}
int wasd(string ab,string ba){
    int numnum=0;
    for(int i=0;i<min(ab.size(),ba.size());i++){
        if(ab[i]==ba[i]){
           numnum+=(ab[i]-'0')*pow(2,i);
        }
    }
    return numnum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==2){
        int cnt=-1e9;
        for(int i=0;i<n;i++){
            cin>>a[i];
            dfs(i,a[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt=max(cnt,wasd(h[i],h[j]));
            }
        }
        cout<<cnt;
        return 0;
    }
    else {
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<a[m-1];
    }
    return 0;
}
