#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f[N], st[N], ans[N];
bool cmp(int a, int b) {
    return a>b;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>f[i];
    if(m==2){
       int ans=0;
       for(int i=1; i<n; i++){
           for(int j=i+1; j<=n; j++){
                   ans=max(ans, f[i]&f[j]);
               }
           }
           cout<<ans;
        return 0;
    }
    if(m==1){
            int ans=0;
            for(int i=1; i<=n; i++) ans=max(ans, f[i]);
            cout<<ans;
            return 0;
    }
    if(m==n){
            for(int i=1; i<n; i++) f[n]=f[n]&f[i];
            cout<<f[n];
            return 0;
    }
    sort(f+1, f+n+1, cmp);
    int top=0, anss=f[1];
    for(int i=1; i<=n; i++){
        if(i<=m){
            ans[i]=(anss&=f[i]);
            st[++top]=i;
        }
        else{
            int topp=top, x=ans[st[top-1]]&f[i];
            if(ans[st[top-1]]&f[i]>ans[st[top]]){
                //cout<<x<<endl;
                st[top]=i;
                ans[i]=ans[i-1]&f[i];
                while((top>2&&ans[st[top-1]]<ans[st[top-2]]&f[i])){
                    top--;
                    swap(st[top-1], st[top]);
                }
                top=topp;
            }
            else {
                ans[i]=ans[i-1];
            }
        }
        //cout<<ans[i]<<' ';
    }
    cout<<ans[n];

    return 0;
}
