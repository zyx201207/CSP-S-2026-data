#include<bits/stdc++.h>
using namespace std;
int a[200005]={};
char c[200005]={};
char get(long long n){
    long long sum=0;
    int i;
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum>=n) break;
    }
    return c[i];
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0,s1,s2;
    long long cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    if(l%2==0){
        s1=l/2;
        s2=s1+1;
    }else{
        s1=l/2;
        s2=s1+2;
    }
    l/=2;
    for(long long i=0;i<l;i++){
        //cout<<(int)get(s1-i)<<' '<<(int)get(s2+i)<<endl;
        if(get(s1-i)!=get(s2+i)) cnt++;
    }
    cout<<cnt;
}
