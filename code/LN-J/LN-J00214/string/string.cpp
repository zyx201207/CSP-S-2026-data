#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s=0;
    int n;
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        s+=l;
        char ad;
        cin>>ad;
        for(int i=0;i<l;i++){
            a+=ad;
        }
    }
    int l=0,r=s-1;
    long long num=0;
    while(l<r){
        if(a[l]!=a[r]){
            num++;
        }
        l++;
        r--;
    }cout<<num;
    return 0;
}
