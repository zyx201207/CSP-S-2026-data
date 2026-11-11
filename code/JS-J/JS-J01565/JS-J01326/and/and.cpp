#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int arr[100010];
unordered_set<int> cnt[35];
unordered_set<int> andset(const unordered_set<int>& a,const unordered_set<int>& b){
    unordered_set<int> ans;
    for(int i:a)if(b.count(i)!=0)ans.insert(i);
    return ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=0;j<=30;j++){
            if(arr[i]&(1<<j)){
                cnt[j].insert(i);
            }
        }
    }int val=0;unordered_set<int> st;
    for(int i=1;i<=n;i++)st.insert(i);
    for(int i=30;i>=0;i--){
        unordered_set<int> tmp=andset(st,cnt[i]);
        if(tmp.size()<m)continue;
        else{st=tmp;val+=(1<<i);}
    }cout<<val<<endl;
    return 0;
}
