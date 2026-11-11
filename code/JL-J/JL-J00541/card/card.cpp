#include<bits/stdc++.h>
using namespace std;
int a[200005],c[100005];
bool b[100005];
stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=10000){
        for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            if(b[a[j]]==1){
                while(s.top()!=a[j]&&!s.empty()){
                    b[s.top()]=0;
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
            }
            else{
                s.push(a[j]);
                b[a[j]]=1;
            }
        }
        while(!s.empty()){
            c[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    }
    else{
        for(int i=1;i<=n;i++){
            c[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            cout<<c[i]<<" ";
        }
    }
    return 0;
}
