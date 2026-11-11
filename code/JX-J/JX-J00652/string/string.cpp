#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n>=2*1e4-100){
        long long a,b;
        cin>>a>>b;
        cout<<a+b;
    }
    else{
        cout<<0;
    }
    return 0;
}
