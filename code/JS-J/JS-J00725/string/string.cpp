#include<bits/stdc++.h>
using namespace std;
string s[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sum=0,k=1;
    int ok=1;
    int f=0;
    char ck;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char a;
        if(ck!=a&&f)ok=0;
        cin>>x>>a;
        ck=a;
        for(int i=k;i<x+k;i++){
            s[i]=a;
        }
        k+=x;
        f=1;
    }
    if(ok==1){
        cout<<0;
        return 0;
    }
    // for(int i=1;i<=k;i++){
    //    cout<<s[i];
    // }
    cout<<endl;
    int t=k/2;
    for(int i=1;i<=t;i++){
        if(s[i]==s[k-i]){
            continue;
        }else{
            sum++;
        }
    }
    cout<<sum;
}
