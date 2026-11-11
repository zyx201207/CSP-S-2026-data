#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a>b;
}
int n,m,a[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        int qwer=a[i];
        int qwq=0;
        while(qwer){
            qwq+=qwer%2;
            qwer/=2;
        }
        if(qwq==1){
            a[i]=0;
        }
    }
    sort(a,a+n,cmp);
    long long ans;

    if(m==1){
    }else{
        ans=a[0];
        for(long long i=1;i<m;i++){
            ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}
