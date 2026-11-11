#include <bits/stdc++.h>
using namespace std;
int c;
long long sec(){
    long long n,d;
    cin>>n>>d;
    long long x[n];
    for(long long i=0;i<n;i++){
        cin>>x[i];
    }
    if(n<=3){
        return 0;
    }
    if(x[n-1]-x[0]<=d){
        return 0;
    }
    if(c==11||c==12){
        if(2*(abs(x[1]-x[0]))>d){
            return 0;
        }

    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<sec();
    }
    return 0;
}
