#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10,MAXM=3e5+10;
int a[MAXN];
int n,m;

unordered_map<int,int> mp;
int ans[MAXM];
void solve1(){
    vector<int> nums;
    for(int i=1;i<=n;i++){
        nums.clear();
        mp.clear();
        // each round
        int j=i;
        while(j<=n){
            if(mp[a[j]]){
                while(nums.back()!=a[j]){
                    mp[nums.back()]=0;
                    nums.pop_back();
                }
                nums.pop_back();
            }
            mp[a[j]]=1;
            nums.push_back(a[j]);
            j++;
        }
        for(int x:nums) ans[x]++;
    }

    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    exit(0);
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n*n<=100000000) solve1();

    return 0;
}
