#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[7000000];
    long long n,ans=0,a,num=0;
    cin>>n;
    if(n>6000000){
        cout<<0;
        return 0;
    }
    while(n--){
        cin>>a;
        if(a>=6000000||num>=6000000){
            cout<<0;
            return 0;
        }
        char s1;
        cin>>s1;
        while(a--){
            s[num]=s1;
            num++;
        }
    }
    for(int i=0;i<num/2;i++){
        if(s[i]!=s[num-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
