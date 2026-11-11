#include <bits/stdc++.h>
using namespace std;
string zf[10000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long n;
    cin>>n;

    long long num=0;
    string zm;

    long long j=0;
    for(long long i=1;i<=n;i++){

        cin>>num>>zm;
        while(num){
            j++;
            num--;
            zf[j]=zm;
        }
    }

    long long th=0;
    long long nn=j/2;

    long long i=1,k=j;

    while(i<=nn && k>nn){
        if(zf[i]!=zf[k]){
            th++;
        }
        i++;
        k--;
    }

    cout<<th;
    return 0;
}
