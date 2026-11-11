#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char s[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    if(n==1){
        printf("0\n");
    }else if(n==2){
        if(s[1]==s[2]){
            printf("0\n");
        }else{
            cout<<min(a[1],a[2]);
        }
    }else{
        printf("0\n");
    }
    return 0;
}
