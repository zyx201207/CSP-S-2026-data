#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;
    cin >> n;
    //string s;
    long long a[n];
    string c[n];
    int zs = 0;
    for(int i = 0;i<n;i++){
        cin >>a[i]>>c[i];
        zs+=a[i];
    }string s[n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<a[i];j++){
            s[i]+=c[i];
        }
    }

    //string ss[n];
    //for(int i = n;i>=--1;i--){
    //    ss[n-i]+=s[i];
    //}


    int sum=0;
    for(int i = 0;i<n;i++){
        if(c[i]==c[1+1]){
            sum++;
        }
    }if(sum==n||sum==n-1){
    cout<<0;
    }
    else{
    cout<<zs/a[1];
    }


    //for(int i = 0;i<n;i++){
    //    for(int j = 0;j<a[i])
    //}
    return 0;
}
