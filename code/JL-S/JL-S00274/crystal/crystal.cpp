#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,mi=0;
    cin>>n>>m;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ma=0;
    for(int i=0;i<n;i++){
        int j=1;
        while(i+j<n){
            if(m<a[i+j]-a[i+j-1]){
                break;
            }
            else{
                m=m-a[i+j]+a[i+j-1];
                j++;
            }
        }
        ma=max(ma,j);
    }
    cout<<ma;
    return 0;
}
