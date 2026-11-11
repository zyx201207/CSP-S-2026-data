#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],c[M],q[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000&&m<=3000){
        for(int i=1;i<=n;i++){
            stack<int>mo;
            memset(q,0,sizeof(q));
            for(int j=i;j<=n;j++){
                if(!q[a[j]]){
                    mo.push(a[j]);
                    q[a[j]]++;;
                }
                else{
                    while(!mo.empty()&&mo.top()!=a[j]){
                        q[mo.top()]--;
                        mo.pop();
                    }
                }
            }
            while(!mo.empty()){
                c[mo.top()]++;
                mo.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cout<<c[i]<<' ';
        }
        return 0;
    }
    else if(m<=2){
        if(m==1){
            cout<<n;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]){
                c[a[i]]++;
            }
            else{
                c[1]++;
                c[2]++;
            }
        }
        cout<<c[1]<<' '<<c[2];
        return 0;
    }
    return 0;
}
