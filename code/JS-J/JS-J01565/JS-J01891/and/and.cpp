#include<bits/stdc++.h>
using namespace std;
vector<int> num(200001);
int all=0,n,m;
void mx(int cnt,int idx,int ad){
    if(ad<=all) return;
    if(cnt==0){
        all=max(all,ad);
        return;
    }
    if(idx>n) return;
    mx(cnt-1,idx+1,ad&num[idx]);
    mx(cnt,idx+1,ad);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>num[i];
    }
    mx(m,1,2147483647);
    cout<<all;
    return 0;
}
