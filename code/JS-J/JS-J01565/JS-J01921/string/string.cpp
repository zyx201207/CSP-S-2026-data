#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,lenth=1,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long len;
        char a;
        cin>>len>>a;
        for(int j=lenth;j<lenth+len;j++){
            if(i==1 && j==1) s+=a;
            s+=a;
        }
        lenth=lenth+len;
    }
    lenth--;
    for(int i=1;i<=lenth/2;i++){
        if(s[i]!=s[lenth-i+1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
