#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
long long s;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        s+=(a[i]-a[i-1])*i;
        if(i==n-1){
            cout<<i+1<<endl;
            break;
        }
        if(s>m){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
