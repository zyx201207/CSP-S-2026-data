#include<bits/stdc++.h>
using namespace std;
long long a,b,v[100005];
int main(){
    long long mav=0;
    cin>>a>>b;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(long long i=1;i<a;i++){
        cin>>v[i];
        if(mav<=v[i]){
            mav=v[i];
        }
    }
    cout<<mav;
}
