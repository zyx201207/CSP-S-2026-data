#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    char s;
    long long t;
    string num;
    long long x=0,c=0;
    for(int i=0;i<n;i++){
        cin>>t>>s;
        c=c+t;
        for(int j=0;j<t;j++){
            num[x]=s;
            x++;
        }
    }
    long long l=0,r=c-1,a=0;
    while(l<=r){
        if(num[l]!=num[r]){
            a++;
        }
        l++;
        r--;
    }
    cout<<a;
    return 0;
}
