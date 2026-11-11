#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000005],m,ans,n;
//bool flag[1000005];
vector<int> used;
void dfs(int deep){
    if(deep==m){
        int num=a[used[0]];
        bool flag[10005]={0};
        for(int i=0;i<m;i++){
            if(flag[used[i]]==false) flag[used[i]]=true;
            else return;
        }
        for(int i=1;i<m;i++){
            num&=a[used[i]];
        }

        ans=max(ans,num);
        return;
    }
    for(int i=deep;i<=n;i++){
        used.push_back(i);

        dfs(deep+1);
        used.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0);
    cout<<ans;
    return 0;
}
