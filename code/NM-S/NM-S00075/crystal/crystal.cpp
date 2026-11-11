#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500009];
queue<long long> h;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long p=a[1],u;
    int maxn=1;
    h.push(p);
    for (int i=2;i<=n;i++){
        if (a[i]!=p){
            u=h.size();
            if (u*(a[i]-p)<=m){
                m-=u*(a[i]-p);
                p=a[i];
                h.push(a[i]);
            }
            else if(u*(a[i]-p)>m){
                while(1){
                    long long d=h.front();
                    h.pop();
                    m+=(p-d);
                    u--;
                    if (u==0){
                        break;
                    }
                    if (u*(a[i]-p)<=m){
                        m-=u*(a[i]-p);
                        p=a[i];
                        h.push(a[i]);
                        break;
                    }

                }
                if (u==0){
                    p=a[i];
                    h.push(a[i]);
                }
            }
        }
        else if (a[i]==p){
            h.push(a[i]);
        }
        u=h.size();
        if (u>maxn){
            maxn=u;
        }
    }
    cout<<maxn;
    return 0;
}
