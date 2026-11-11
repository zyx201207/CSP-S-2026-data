#include<bits/stdc++.h>
using namespace std;
string all;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long nn=1;
    for(int i=1;i<=n;i++){
        long long t;
        string a;
        cin>>t;
        cin>>a;
        for(long long j=1;j<=t;j++){
            all[nn]=a[0];
            nn++;
        }
    }
    long long cnt=nn,ans=0;//all+1
    if((cnt-1)%2==0){
        for(long long i=1;i<=cnt/2;i++){
            if(all[i]!=all[cnt-i]){
                ans++;
            }
        }
    }
    else{
        for(long long i=1;i<=cnt/2+1;i++){
            if(all[i]!=all[cnt-i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
