#include <bits/stdc++.h>
using namespace std;
long long n,sum=0,cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string a,b;
    for(int i=1;i<=n;i++){
        long long c;
        string d;
        cin>>c>>d;
        for(int j=1;j<=c;j++) a+=d;
    }
    for(int i=a.size()-1;i>=0;i--) b+=a[i];
    if(a==b){
        cout<<0;
        return 0;
    }
    if(a.size()%2!=0) sum=a.size()/2+1;
    else sum=a.size()/2;
    for(int i=0;i<sum;i++){
        if(a[i]!=b[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
