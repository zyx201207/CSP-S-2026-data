#include<bits/stdc++.h>
using namespace std;
long long n,b,k=1,j=1,p;
string a,d,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>c;
        for(int i=1;i<=b;i++){
            a=a+c;
            k++;
        }
    }
    for(int i=k-1;i>=0;i--){
        d[j]=a[i];
        j++;
    }
    for(int i=1;i<=k/2;i++){
        if(a[i]!=d[i]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
