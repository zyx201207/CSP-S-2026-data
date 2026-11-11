#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int y[N];
int a[N];
bool b[N];
int ans[N];
int c[N];
int w[N];
stack<int> p;
int main()
{
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    cin>>n>>m;
    int cnt=0,last=1;
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        y[c[i]]++;
        if(c[i]<c[i-1])A=0;
        if(c[i]>c[i-1])w[c[i]]=i;
    }
    if(m<=2){
        if(m==1){
            cout<<n;
            return 0;
        }
        if(m==2){
            if(c[n]==1)cout<<n<<" "<<y[2];
            else cout<<y[1]<<" "<<n;
        }
        return 0;
    }
    if(A){
        for(int i=1;i<=m;i++){
            cout<<n-w[i]+1<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=c[i+1]){
            a[++cnt]=c[i];
            c[cnt]=last;
            last=1;
        }
        else last++;
       // cout<<c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
           if(b[a[j]]){
               while(p.top()!=a[j]){
                   b[p.top()]=0;
                   p.pop();
               }
           } 
           else{
               p.push(a[j]);
               b[a[j]]=1;
           }
        }
        while(!p.empty()){
            ans[p.top()]+=c[i];
            b[p.top()]=0;
            p.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
