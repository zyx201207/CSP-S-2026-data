#include <bits/stdc++.h>
using namespace std;
long long a[20000002],b[20000002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,m,num=0,sum=0;
    cin>>n;
    char s;
    long long j=0;
    for(long long i=0;i<n;i++){
        cin>>m;
        cin>>s;
        num+=m;
        while(m){
            a[j++]=s-'a';
            m--;
        }
    }

    for(long long i=0;i<num;i++){
        if(a[i]!=a[num-1-i]){
            sum++;
        }
    }
    cout<<sum/2;


    return 0;
}
