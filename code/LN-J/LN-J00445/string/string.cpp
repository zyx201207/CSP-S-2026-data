#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){

    string str="";
    long long n;cin>>n;

    for(long long i = 0;i<n;i++){
        long long a;cin>>a;
        string b;
        cin>>b;
        for(long long j = 0;j<a;j++){
            str += b;
        }
    }
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
    long long ans=0;
    long long c = str.length();
    for(long long i = 0;i<=c/2;i++){
        if(str[i] != str[c-1-i]){
            ans+=1;
        }
    }
    cout<<ans;












    return 0;
}
