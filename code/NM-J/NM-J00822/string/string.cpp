#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,c=0,cn=0;
    cin>>n;
    long long l[n],zl=0;
    string s1[n];
    for(int i=0;i<n;i++){
        cin>>l[i];
        zl+=l[i];
        cin>>s1[i];
    }
    string s[zl];
    for(int i=0;i<n;i++){
        for(int j=0;j<l[i];j++){
            s[c]=s1[i][0];
            c++;
        }
    }
    for(int i=0;i<zl/2;i++){
        if(s[i]!=s[zl-1-i]){
            cn++;
        }
    }
    cout<<cn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
