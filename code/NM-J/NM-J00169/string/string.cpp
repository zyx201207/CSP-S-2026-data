#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,max,c;
    char b;
    cin>>n;
    cin>>a>>b;
    max=a;
    c=b;
    for(int i=1;i<n;i++){
        cin>>a;
        cin>>b;
        if(a>max){
            max=a;
        }

    }
    if(max<=10){
        cout<<2;
    }
    elseif(max>10&&max<50){
        cout<<20;
    }
    elseif(max>50&&max<100){
        cout<<50;
    }
    else{
        cout<<n/2*max;
    }
    return 0;
}

