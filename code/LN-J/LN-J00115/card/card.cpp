#include<bits/stdc++.h>
using namespace std;
    stack<int>p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>m>>n;
    int a[m+1],b[n+1],cnt[n+2];
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
    memset(b,0,sizeof b);
        for(int j=i;j<=m;j++){
            if(b[a[j]]==0){
                p.push(a[j]);
                //cout<<i<<": "<<a[j]<<" is pushed"<<endl;
                b[a[j]]=1;
            }
            else
                while(!p.empty()){
                        if(p.top()==a[j]){
                            break;
                        }
                        //cout<<i<<": "<<p.top()<<" is lost"<<endl;
                    b[p.top()]=0;
                    p.pop();
                }
        }
        while(!p.empty()){
            cnt[p.top()]++;
            p.pop();
        }
    }
    for(int i=1;i<=n;i++)
        cout<<cnt[i]<<" ";
    return 0;
}
