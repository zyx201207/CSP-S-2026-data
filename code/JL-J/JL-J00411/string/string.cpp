#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c;
    cin>>n,a,b,c;
    a=n/100;
    b=n/10%10;
    c=n%10;
    for(int i=0;i<=n;i++){
        if(n==c*100+b*10+a){
        cout<<n;
    }
    }
    return 0;
}
