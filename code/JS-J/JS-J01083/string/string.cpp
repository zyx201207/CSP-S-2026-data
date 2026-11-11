#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n;
string ans;
ll cnt;
int sum;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i = 1;i <= n;i++){
        int x;
        sum+=x;
        string y;
        cin>>x;
        cin>>y;
        for(int j = 1;j <= x;j++){
            ans=ans+y;
        }
    }
    int z=(sum+1)/2;
    for(int i = 0;i < z;i++){
        if(ans[i]!=ans[sum-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
