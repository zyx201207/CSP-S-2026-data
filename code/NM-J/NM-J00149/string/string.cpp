#include<bits/stdc++.h>
using namespace std;

struct node{
    long long b;
    char c;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n=0;
    scanf("%lld",&n);
    node a[200005]={};
    for(long long i=1;i<=n;i++){
        node t={};
        scanf("%lld",&t.b);
        cin>>t.c;
        a[i]=t;
    }
    string s1;
    string s2;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=a[i].b;j++){
            s1+=a[i].c;
        }
        for(long long j=1;j<=a[n-i+1].b;j++){
            s2+=a[n-i+1].c;
        }
    }
    long long ans=0;
    long long sum=0;
    sum=s1.length();
    if(n%2==0){
        sum/=2;
    }else{
        sum/=2;
        sum++;
    }
    for(long long i=0;i<sum;i++){
        if(s1[i]!=s2[i]){
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
221
abc
cba
122
*/
