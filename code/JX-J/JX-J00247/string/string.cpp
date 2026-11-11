#include<bits/stdc++.h>
using namespace std;
long long n,lmin,rmin;
string a,l,r,lf,rf;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long t;
        char c;
        cin>>t>>c;
        for(int j=1;j<=t;j++){
            a+=c;
        }
    }
    for(int i=0;i<a.size()/2;i++){
        l+=a[i];
    }
    for(int i=a.size()/2-1;i>=0;i--){
        lf+=a[i];
    }
    if(a.size()%2==0){
        for(int i=a.size()/2;i<a.size();i++){
            r+=a[i];
        }
        for(int i=a.size()-1;i>=a.size();i--){
            rf+=a[i];
        }
    }else{
        for(int i=a.size()/2+1;i<a.size();i++){
            r+=a[i];
        }
        for(int i=a.size()-1;i>=a.size()/2+1;i--){
            rf+=a[i];
        }
    }
    for(int i=0;i<l.size();i++){
        if(l[i]!=rf[i])  lmin++;
        if(r[i]!=lf[i])  rmin++;
    }
    cout<<min(lmin,rmin);
    return 0;
}
