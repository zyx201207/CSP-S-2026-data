#include<bits/stdc++.h>
using namespace std;
long long a,b[1000000],ch;
string z[10000000],c[10000000],dc[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i]>>z[i];
    }
    for(int i=1;i<=a;i++){
        for(int q=1;q<=b[i];q++){
            c[q]=z[i];
        }
    }
    for(int i=a;i<=1;i--){
        for(int q=b[i];q<=1;q--){
            dc[q]=z[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
