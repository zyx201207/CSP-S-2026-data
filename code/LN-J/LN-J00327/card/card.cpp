#include<bits/stdc++.h>
using namespace std;
//尽力了，为何不输出
int n,m;
int a[200003],point[200003],fa[3003],mi[3003],ans[3003];
void ans_add(int i){
    while(i<n){
        ans[a[i]]++;
        i=fa[i]+1;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=m;i++)mi[i]=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(mi[a[i]]==-1){
            mi[a[i]]=i;
            fa[a[i]]=i;
        }
        else if(mi[a[i]]>=0){
            point[mi[a[i]]]=i;
            fa[a[i]]=i;
            mi[a[i]]=i;
        }

    }
    ans_add(0);
    for(int i=0;i<n;){
        if(fa[a[i]]==i)i++;
        else {
            int t=point[i];
            for(int j=i+1;j<t;j++){
                if(fa[a[j]]==j)ans[a[j]]+=j-i;
                else {
                    ans_add(j);
                    i=j;
                    break;
                }
            }
        }
    }for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
