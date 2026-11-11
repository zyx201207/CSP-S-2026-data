#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int ans;
        cin>>ans;
        if(ans>sum) sum=ans;
    }
    cout<<sum;
    return 0;
}
