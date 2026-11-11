#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(m==1){
        int a,maxx=-1;
        for(int i=1;i<=n;i++){
            cin>>a;
            maxx=max(maxx,a);
        }
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    unique(a+1,a+n+1);
    int maxn=-1;
    for(int i:a){
        for(int j:a){
            if(i!=j){
                int c=(i&j);
                maxn=max(maxn,c);
            }
        }
    }
    cout<<maxn;
    return 0;
    }
    if(m>2){
        priority_queue<long long> p;
        int a;
        for(int i=1;i<=n;i++){
            cin>>a;
            p.push(a);
        }
        int b[n+1];
        for(int i=1;i<=m;i++){
            b[i]=p.top();
            p.pop();
        }
        int c=b[1];
        for(int i=2;i<=m;i++){
            c=c&b[i];
        }
        cout<<c;
        return 0;
    }
}
