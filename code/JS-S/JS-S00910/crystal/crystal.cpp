#include<bits/stdc++.h>
using namespace std;
long long n,m,A[500002],l=0,r=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    A[0]=A[1];
    while(r<=n){
        m-=(A[r+1]-A[r])*(r-l);
        r++;
        if(m<0){
            l++;
            m+=(A[r]-A[l]);
        }
    }
    cout<<r-l-1;
    return 0;
}
