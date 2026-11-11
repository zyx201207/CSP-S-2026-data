#include<bits/stdc++.h>
using namespace std;
long long a=0,b=0,c[200001]={},m=0,z=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    sort(1+c,1+c+a);
    m=c[a];
    for(int i=a-1;i>=1;i--){
        z++;
        m=m&c[i];
        if(z==b-1){
            break;
        }
    }
    cout<<m;
    return 0;
}
