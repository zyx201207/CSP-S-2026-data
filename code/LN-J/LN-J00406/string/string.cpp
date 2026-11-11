#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int flag;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }

    for(int i = 1; i <= n - 1; i++){
        if(c[i] == c[i + 1]){
            flag = 1;
        }
        else{
            flag = 0;
        }
    }

    if(flag == 1 || n == 1){
        cout<<"0";
    }

    return 0;
}
