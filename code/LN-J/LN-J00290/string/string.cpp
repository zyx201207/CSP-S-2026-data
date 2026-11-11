#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
long long s1[N],s2[N];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;cin>>n;
    long long a,c;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        cnt=a*c;
        s1+=cnt;
    }
    for(int i=n;i>=1;i--){
        s2=a*c
    }
    for(int i=1;i<=n;i++){
        if(s1!=s2){
            s2=s1;

        }else{
            cout<<0;
        }
    }



    return 0;
}
