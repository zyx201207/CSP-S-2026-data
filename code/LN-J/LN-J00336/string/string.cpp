#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    char ss[n+5]={0};
    long long len=0;
    long long j=0;
    for(long long i=0;i<n;i++){
        char s;
        j=i;
        long long x;
        cin>>x>>s;
        while(x--){
            ss[i+j]=s;
            j++;
            len++;
        }
    }
    char neww[n+5];
    long long t=len/2;
    long long k=-1;
    for (int i=t-1;i>=0;i--){
        neww[k]=ss[i];
        k++;
    }
    long long count=0;
    for (long long i=len-1;i>t;i--){
        if(neww[i]!=ss[i]) count++;
    }
    cout<<count;
    return 0;
}

