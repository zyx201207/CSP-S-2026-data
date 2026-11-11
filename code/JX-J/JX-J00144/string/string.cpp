#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,b=0;
    cin>>n;
    char x[1000086];
    int y[1000086];
    for(int i=1;i<=n;i++){
            char v;
            cin>>y[i]>>v;
        for(int j=1;j<=y[i];j++){
            x[j]='v';
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(x[j]!=x[i]) b++;
        }
    }
    cout<<b;

    return 0;
}
