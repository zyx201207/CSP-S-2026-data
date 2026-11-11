#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001];
bool c[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int>s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(c[a[j]]){
                while(s.top()!=a[j]){

                    c[s.top()]=0;
                    s.pop();
                }
            }else{
                c[a[j]]=1;
                s.push(a[j]);
            }
        }
        for(int j=1;j<=m;j++){
            c[j]=0;
        }
        while(!s.empty()){
            b[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
