#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2*1e5+7;
struct zh{
    int ln;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    long long len=0;
    string s="";
    for(int i=1;i<=n;i++){
        cin>>a[i].ln>>a[i].c;
        len+=a[i].ln;
        for(int j=1;j<=a[i].ln;j++){
            s+=a[i].c;
        }
    }
    for(int i=0;i<(len+1)/2;i++){
        cnt+=!(s[i]==s[len-i-1]);
    }
    cout<<cnt;
    return 0;
}
