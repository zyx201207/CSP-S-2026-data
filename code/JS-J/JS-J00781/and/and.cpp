#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
vector<int> ans;
bool cmp(int x,int y){
    return x>y;
}
void ass(int step,int x,int y){
    if(step==m){
        for(int i=x;i<=n;i++){
            ans.push_back(a[i]&y);
        }
        return;
    }
    for(int i=x;i<=n;i++){
        if(y!=0) ass(step+1,i+1,a[i]&y);
        else ass(step+1,i+1,a[i]);
    }
    return;
}
signed main(){
    freopen("and4.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]!=a[j]) break;
            a[j]=0;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;a[i]!=0;i++){
        n=i;
    }
    ass(1,1,0);
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans[0];
    return 0;
}
