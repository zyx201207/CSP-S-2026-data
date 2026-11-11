#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    long long len=0;
    long long f=0;
    string l="";
    string l1="";
    string l2="";
    string l3="";
    for(int i=0;i<n;i++){
        int x[n];char y[n];
        cin>>x[i]>>y[i];
        len+=x[i];
        for(int j=0;j<x[i];j++){
            l=l+y[i];
        }
    }
    for(long long i=0;i<len;i++){
        char c=l[i];
        if(i<len/2){
            l1+=c;
        }
        if(i>len/2&&len%2!=0){
            l2+=c;
        }
        if(i>=len/2&&len%2==0){
            l2+=c;
        }
    }
    for(long long i=l2.length()-1;i>=0;i--){
        char c=l2[i];
        l3+=c;
    }
    for(long long i=0;i<l2.length();i++){
        char x=l1[i]; char y=l3[i];
        if(x!=y){
            f++;
        }
    }
    cout<<f;
    return 0;
}
