#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+7;
int ans;
string s;
int n;
long long a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int ii=0;
    for(int i=0;i<n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int i=0;i<x;i++){
            a[ii]=y;
            ii++;
        }
    }
    int max1=0,max2=0;
    int mid1=ii/2+ii%2,mid2=ii/2+ii%2;
    int b[mid1],c[mid1];
    for(int i=0;i<mid1;i++){
        b[i]=a[i];
    }
    int iii=0;
    for(int i=n;i>mid1;i--){
        c[iii]=a[i];
        iii++;
    }
    for(int i=0;i<mid1;i++){
        if(b[i]!=c[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

