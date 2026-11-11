#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long i=0,j=0,m=0,k=0,ban=0,ci=0,shu=0,l=0;
    long n=0;
    string s,c;
    cin>>n;
    long long a[n];
    for(i=n;i>=1;i--){
        cin>>a[i]>>c[i];
    }
    for(n;n>0;n--){
        for(k=a[n];k>0;k--){
            s[m]=c[n];
            m++;
        }
    }
    m=m-1;
    if(m%2==0){
        ban=m/2-1;
    }else{
        ban=m/2;
    }
    for(ci=ban;ci>=0;ci--){
        if(s[ci]!=s[m-ci]){
            shu++;
        }
    }

    cout<<shu<<endl;


    return 0;
}




