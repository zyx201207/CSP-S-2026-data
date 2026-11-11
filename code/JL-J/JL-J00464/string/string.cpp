#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,len=0,ans=0;
    string str="";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string b;
        cin>>a>>b;
        len+=a;
        for(int i=1;i<=a;i++){
            str+=b;
        }
    }
    for(int i=0;i<len/2;i++){
        if(str[i]!=str[len-i-1]) ans+=1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
