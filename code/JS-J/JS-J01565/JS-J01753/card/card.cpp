#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        vector<int> v;
        for(int k = i;k <= n;k++){
            int flag = 0;
            for(int j = 0;j < v.size();j++){
                if(flag==1)v[j] = 0;
                if(v[j]==a[k])flag=1;

            }
            if(flag==0)v.push_back(a[k]);
        }
        for(int j = 0;j < v.size();j++){
            ans[v[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)cout<<ans[i]<<' ';
    return 0;
}
