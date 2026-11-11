#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,j=1,d;
    cin>>n;
    long long a[n+10]={};
    char c[n+10]={};
    char b[n+10]={};
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)
        for(int q=1;q<=a[i];q++){
            b[j]=c[i];
            j++;}
    j--;
    d=j;
    j=j/2;
    for(int i=1;i<=j;i++)
        if(b[i]!=b[d-i+1])
            sum++;
    cout<<sum;
    return 0;
}
