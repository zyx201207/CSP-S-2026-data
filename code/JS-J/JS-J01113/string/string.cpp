#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        long long t;
        char c;
        cin>>t>>c;
        while(t--){
            a=a+c;
            b=c+b;
        }
    }
    for(long long i=0;i<=(a.size())/2;i++){
        if(a[i]!=b[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
