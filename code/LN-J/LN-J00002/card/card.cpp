#include <bits/stdc++.h>
using namespace std;
const int maxn =5e5+10;
const int maxm=3e5+10;
int a[maxn];
int t1[maxm];
int t2[maxm];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t1,0,sizeof(t1));
        for(int j=i;j<=n;j++){
            if(t1[a[j]]==0){
                s.push(a[j]);
                t1[a[j]]++;
            }
            else {
                while(!s.empty() && s.top()!=a[j]){
                    t1[s.top()]--;
                    s.pop();
                }
                s.pop();
                s.push(a[j]);
            }
        }
        for(int j=1;j<=m;j++){
            if(t1[j]!=0) t2[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t2[i]<<" ";
    }
    return 0;
}
