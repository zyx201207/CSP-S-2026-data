#include<bits/stdc++.h>
using namespace std;
int a[500005],t[300005];
bool v[300005];
int n,m;
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(v[a[j]]){
                v[s.top()]=0;
                s.pop();
            }
            s.push(a[j]);
            v[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(v[j]){
                t[j]++;
                s.pop();
                v[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << t[i] << ' ';
    }
    return 0;
}
