#include<bits/stdc++.h>
using namespace  std;
long long n;
int min=0,max=0;
string s[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        long long c;
        char b;
        cin>>c>>b;
        for(int j=1;j<=c;j++){
             if(c+s[1]=b-c){
                min+=max;
             }
             else  max+=min;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

