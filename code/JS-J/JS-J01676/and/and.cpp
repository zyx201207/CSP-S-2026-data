#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans;
//bool vis[200005];
int n;
void dfs(int m,int j,long long sum){
    if(m==0){
        ans=max(ans,sum);
    }
    if(j>n){
        return;
    }
    dfs(m,j+1,sum);
    sum=sum&a[j];
    dfs(m-1,j+1,sum);
}
set<int>s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=30;i++){
        s.insert(pow(2,i)-1);
    }
    bool ta=true;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(s.erase(a[i])){
            s.insert(a[i]);
            if(a[i]==0){
                cnt++;
            }
        }else{
            ta=false;
        }
    }
    if(ta){
        if(n-cnt<m){
            cout<<0;
        }else{
            sort(a+1,a+n+1);
            cout<<a[n-m+1];
        }
        return 0;
    }

    for(int i=1;i<=n;i++){
        dfs(m-1,i+1,a[i]);
    }
    cout<<ans;
    return 0;
}



