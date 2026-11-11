#include<bits/stdc++.h>
using namespace std;
struct node{
    int shu;
    char d;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].shu>>a[i].d;
    }
    if(n==1) cout<<"0";
    else if(n==2){
        if(int(a[1].d)==int(a[2].d)){
            cout<<"0";
        }
        else{
            cout<<min(a[1].shu,a[2].shu);
        }
    }
    return 0;
}
