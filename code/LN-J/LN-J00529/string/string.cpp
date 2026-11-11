

#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen(pow.in,"r",stdin);
    long long a[200005]={};
    string b[200005]={};
    long long t1=0,t2=0;
    int n;
    cin>>n;
    string s="";

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s=s+b[i];
        }

    }
    string st=b[1];
    int f3=0;
    for(int i=2;i<=n;i++){
        if(st!=b[i]){
                f3=1;
            break;
        }
    }
    if(f3==0){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2&&a[1]==a[2]&&b[1]!=b[2]){
        cout<<a[2];
        return 0;
    }
    if(n==3&&a[1]==a[3]&&b[1]!=b[3]){
        cout<<a[3];
        return 0;
    }
    if(n%2==0){
        long long c=a[1];
        int f1=0;
        for(int i=2;i<=n/2;i++){
            if(c!=a[i]){
                f1=1;
                break;
            }
        }
    long long d=a[n];
    int f2=0;
    for(int i=n;i>n/2;i--){
        if(d!=a[i]){
                f2=1;
            break;
        }
    }


    for(int i=1;i<=n/2;i++){
        t1+=a[i];
    }
    for(int i=(n/2)+1;i<=n;i++){
        t2+=a[i];
    }
    if(t1==t2&&f1==0&&f2==0){
        cout<<t2;
        return 0;
    }
    }


    int i=0,j=s.size()-1;
    long long t=0;
    while(j>i){
        if(s[i]!=s[j]){
                s[j]=s[i];
            t++;
        }
        i++;
        j--;
    }
    cout<<t;
    return 0;
    freopen(pow.out,"w",stdout);
}


