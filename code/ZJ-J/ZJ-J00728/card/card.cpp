#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10,M=3*1e5+10;
vector<int> s[M];
int cnt[M];
int n,m,a[N];
vector<int> isp;
inline int upper(int x,int j){
    int l=0,r=s[j].size()-1,pos,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(s[j][mid]>x){
            pos=s[j][mid];
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return pos;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        if(s[i].size()>1){
            isp.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]+=i;
    }
    for(int i=1;i<=n;i++){
        for(auto j:isp){
            if(s[j][s[j].size()-1]<i) continue;
            int k=upper(i-1,j);
            for(int l=max(k,i);l<s[j][s[j].size()-1];l++){
                cnt[a[l]]--;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
