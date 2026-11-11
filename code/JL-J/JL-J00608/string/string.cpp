#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#include<iomanip>
using namespace std;
string S[1100];
string c[1100];
string b[1100];
int a[1100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w".stdout);
    int n;
    cin>>n;
    int sum=0;
    int l=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=sum;j<a[i];j++){
            S[i]=c[i];
        }
        sum+=a[i];
        l+=c[i];
    }
    l/=2;
    int x=1;
    for(int i=0;i<n;i++){
        if(c[i]!=c[i-1]){
        x=0;
        }
    }
    if(x==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<l;i++){
        b[i]=c[i];
    }
    for(int i=sum,j=0;i>l,j<l;i--;j++){
        b[i]=b[j];
    }
    int cnt=0;
    for(int i=0;i<sum;i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
