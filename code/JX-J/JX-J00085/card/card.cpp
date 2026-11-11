#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500100],l[300100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        bool b[300100] = {};
        int sum[300100] = {};
        stack<int> s = {};
        for(int j = i;j<=n;j++){
            if(!b[a[j]]){
                s.push(a[j]);
                b[a[j]] = 1;
            }else{
                while(s.top()!=a[j]){
                    b[s.top()] = 0;
                    s.pop();
                }
            }
        }
        while(s.size()){
            sum[s.top()]++;
            s.pop();
        }
        for(int j = 1;j<=m;j++){
            if(sum[j]) l[j]++;
        }
    }
    for(int i = 1;i<=m;i++) cout<<l[i]<<' ';
    return 0;
}
