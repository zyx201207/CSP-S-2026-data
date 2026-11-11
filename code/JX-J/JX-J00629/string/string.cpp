#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1]={};
    int c[n+1]={};
    char S[10086]={};
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int b=0;
    for (int i=1;i<=n;i++){
        b+=a[i-1];
        for (int j=0;j<a[i];j++){
                S[j+b]=c[i];
        }
    }
    int z=0;
    for (int i=0;i<b/2;i++){
        if (S[i]!=S[b-i]){
            z+=1;
        }
    }
    cout<<z;
    return 0;
}
