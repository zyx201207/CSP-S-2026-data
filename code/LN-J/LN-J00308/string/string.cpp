#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[1000000] = {0};
    char c[1000000] ={0};
    int flag =1;
    char b;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(i==1){
            b=c[i];
        }
        if(c[i]!=b){
            flag=0;
        }
    }
    if(flag==1){
        cout<<0;
        return 0;
    }


    return 0;
}
