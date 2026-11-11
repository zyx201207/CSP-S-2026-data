#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t,a[N],v[N],ans;
int f(int n,int d,int x){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]-a[x]>=d){
            ans+=f(n-i,d,i);
        }
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int k=1;k<=t;k++){
        int n,d;
        for(int i=1;i<=n;i++){
           cin>>a[i];
           cout<<f(n,d,1);
        }
    }
    cout<<"0"<<endl<<"1";
    return 0;
}
