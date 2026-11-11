#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int t[300005];
int sum[300004];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[a[i]]++;
        t[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j==t[a[j]]&&sum[a[j]]>1){
                while(s.top()!=a[j])
                    s.pop();
            }
            else
                s.push(a[j]);
        }
        sum[a[i]]--;
        while(s.size())
            ans[s.top()]++,s.pop();
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
