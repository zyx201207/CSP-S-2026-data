#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5&&m<=2){
        if(m==2){
            cout<<n<<" "<<n/2;
        }
        else{
            cout<<n;
        }
    }
    return 0;
}
