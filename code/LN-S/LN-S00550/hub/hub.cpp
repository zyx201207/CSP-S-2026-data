#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000010];
int main(){
    cin>>c>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>a[i];
        }
        cout<<t<<endl;
    }
    return 0;
}
