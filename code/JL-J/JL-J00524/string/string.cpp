#include<bits/std c++.h>
using namespace std;
int main{
    freopen("string.in","w",stdin)
    freopen("string.out","r",stdout)
    int n,sum=0,cut=0;
    string s="";
    while(n--){
        int x;char c;
        for(int i=1;i<=x;i++){
            s=s+c;
        }
        sum+=x;
    }
    for(int i=sum/2;i<sum;i++){
         if(s[i]!=s[sum-1-i])
         cnt++;
    }
    cout<<cnt;
    return 0;
}
