#include<bits/stdc++.h>
using namespace std;
long long a[1000],b[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,mmax=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=i+1;k<n;k++){
                b[k]=a[i]&a[k];
                if(mmax<b[k]){
                    mmax=b[k];
                }
            }
        }
    }
    cout<<mmax;
    return 0;
}
