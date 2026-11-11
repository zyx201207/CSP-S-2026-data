#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0;
    string c1="",c2="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        c2=c2+c[i];
    }
    for(int i=n;i>=1;i--){
        c1=c1+c[i];
    }
    if(c1==c2) cout<<0;
    else{
        for(int i=0;i<n/2;i++){
            if(c1[i]!=c2[i]){
               sum+=min(a[i+1],a[n-(i+1)]);
            }
        }
        cout<<sum;
    }
    return 0;
}
