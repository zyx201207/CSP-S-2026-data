#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
struct zm{
    long long a;
    char b;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    zm m[n];
    for(int i=0;i<n;i++){
        cin>>m[i].a>>m[i].b;
        sum+=m[i].a;
    }
    bool x=true;
    for(int i=1;i<n;i++){
        if(m[i].b!=m[i-1].b){
            x=false;
            break;
        }
    }
    if(x) cout<<"0";
    else cout<<sum/2;
    return 0;
}
