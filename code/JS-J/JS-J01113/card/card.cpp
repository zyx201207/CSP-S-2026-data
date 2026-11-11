#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],count_ju[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>c[i];
    }
    for(long long i=1;i<=n;i++){
        queue<long long>a,b;
        for(long long j=i;j<=n;j++){
            while(!a.empty()){
                if(a.front()!=c[j]){
                    b.push(a.front());
                    a.pop();
                }else{
                    while(!a.empty()){
                        a.pop();
                    }
                }
            }
            while(!b.empty()){
                a.push(b.front());
                b.pop();
            }
            a.push(c[j]);
        }
        while(!a.empty()){
            count_ju[a.front()]++;
            a.pop();
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<count_ju[i]<<" ";
    }
    return 0;
}
