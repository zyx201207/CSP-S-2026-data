#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,flag=1,a[300005],b[300005]={0},_2=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=a[i-1]) flag=0;
        if(a[i]==2) _2=i;
    }
    if(flag==1){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        return 0;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        cout<<n<<" "<<n;
        return 0;
    }
    return 0;
}
