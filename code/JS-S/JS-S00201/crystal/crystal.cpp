#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n],sa[n],ga[n],cha;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ga[i]=1;
        sa[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cha=a[j]-a[i];
            if(sa[j]+cha<=m){
                sa[j]+=cha;
                ga[j]++;
            }
        }
    }
    sort(ga,ga+n);
    cout<<ga[n-1];
    return 0;
}
