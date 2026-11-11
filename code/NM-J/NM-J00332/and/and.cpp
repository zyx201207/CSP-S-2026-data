#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200003];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1] and a[2]){
        //cout<<a[1];
    }
    if(a[1] and a[3]){
        //cout<<"0";
    }
    if(a[2] and a[3]){
        //cout<<a[3];
    }
    if(a[3] and a[4]){
        //cout<<a[3];
    }
    cout<<a[3];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
