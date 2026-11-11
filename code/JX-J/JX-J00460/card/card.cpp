#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],cnt[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
     for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!c[a[j]]){
                c[a[j]]=1;
                s.push(a[j]);
            }else{
                while(!s.empty()&&s.top()!=a[j]){
                    c[s.top()]=0;
                    s.pop();
                }
                s.push(a[j]);
            }
        }
        for(int j=1;j<=m;j++){
            if(c[j]==1)cnt[j]++;
            c[j]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
