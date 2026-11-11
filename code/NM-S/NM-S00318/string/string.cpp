#include <bits/stdc++.h>
using namespace std;
long long a[200011],n,m=0,c;
char s[200011];
char ss[2145671439];
int main(){

    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i]>>s[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<a[i];j++){
            ss[m]=s[i];
            m+=1;
        }
    }
    for(long long k=0;k<m/2+1;k++){
        if(ss[k]!=ss[m-k-1]){
            c++;
        }
    }
    cout<<c;

    return 0;
}
