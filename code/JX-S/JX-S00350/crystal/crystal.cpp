#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i]=c[i-1]+(a[i]-a[i-1])*(i-1);
        //cout<<c[i]<<endl;
        if(c[i]==m){
            int j=i+1;
            while(j<=n){
                if(a[j]!=a[i])break;
                j++;
            }
            cout<<j-1;
            return 0;
        }
        if(c[i]>m){
            cout<<i-1;
            return 0;
        }
    }
    return 0;
}
