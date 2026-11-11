#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int s[1001]={};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(n==1){
        cout<<s[0];
    }


    return 0;
}
