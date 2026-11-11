#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010];
stack<int>q;
set<int>v;
int sum[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>500){
        for(int i=1;i<=n;i++){
            while(!q.empty()){
                q.pop();
            }
            v.clear();
            for(int j=i;j<=n;j++){
                while(q.top()==a[j]){
                        q.pop();
                }
                q.push(a[j]);
                v.insert(a[j]);
            }
            for(int i=1;i<=m;i++){
                if(v.count(i))sum[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<sum[i]<<' ';
        }
    return 0;
    }
    for(int i=1;i<=n;i++){
        while(!q.empty()){
            q.pop();
        }
        v.clear();
        for(int j=i;j<=n;j++){
            while(v.count(a[j])){
                v.erase(q.top());
                q.pop();
            }
            q.push(a[j]);
            v.insert(a[j]);
        }
        for(int i=1;i<=m;i++){
            if(v.count(i))sum[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
return 0;
}
