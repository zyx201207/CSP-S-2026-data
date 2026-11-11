#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,res;
string a,s;
int main(){\
freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);

    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>m>>s;
        sum+=m;
        for(long  long  j=0;j<m;j++){
            a+=s;
        }
    }
    string as=a;
    reverse(a.begin(),a.end());
    for(long long  i=0;i<sum;i++){
        if(as[i]==a[i]){
           res++;
       }
    }

    cout<<sum-res;
    return 0;
}
