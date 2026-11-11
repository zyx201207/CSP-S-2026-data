#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    int n;
    string s;
    cin>>n;
    int m,add=0;
    char a;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        add+=m;
        for(int j=add;j<m+add-1;j++){
            s[j]=a;
        }
    }
    string q,p;
    int ans=0;
    if(add%2==0){
        for(int i=0;i<add/2;i++){
            q[i]=s[i];
        }
        for(int j=0;j<add/2;j++){
            for(int i=add-1;i>=add/2;i--){
                p[j]=s[i];
            }
        }
    }else{
        int b=0;
        b=s[add/2];
        for(int i=0;i<add/2;i++){
            q[i]=s[i];
        }
        for(int j=0;j<add/2;j++){
            for(int i=add-1;i>add/2;i--){
                p[j]=s[i];
            }
        }
    }
    for(int i=0;i<add/2;i++){
        if(p[i]!=q[i]){
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
