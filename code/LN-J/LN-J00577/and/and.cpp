#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
int main(){
    init();
    long long n,m,l=0,p=0;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        p=max(p,a[i]);
    }
    if(m==1){
        cout<<p;
    }
    sort(a,a+n);
    do{
        long long y=a[0];
        for(int i=1;i<m;i++){
            y=y&a[i];
        }
        l=max(y,l);
    }while(next_permutation(a,a+n));
    cout<<l<<endl;
}
