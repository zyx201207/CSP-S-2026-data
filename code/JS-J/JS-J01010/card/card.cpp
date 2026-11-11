#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],s[500005],top=0,ans[300005];
vector<int>v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=n;i>=1;i--)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        if(t[a[i]]==0){
            s[++top]=a[i];
            t[a[i]]=top;
        }
        else{
            top=t[a[i]]-1;
            s[++top]=a[i];
            t[a[i]]=top;
        }
        for(int j=1;j<=top;j++)
            ans[s[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}