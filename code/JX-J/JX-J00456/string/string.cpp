#include<bits/stdc++.h>
using namespace std;
int a[100005];
string c,d,e;
long long n,m=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=0;i<n/2;i++){
       d=c[i];
        for(int j=n/2;0<j;j--){
            e=c[j];
            if(d!=e) m+=a[j];
            else m+=0;
    }
    cout<<m;
    }
    return 0;
}
