#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long n,a,su=0,ans=0;
    char c;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(long long i=0;i<n;i++){
        cin>>a>>c;
        su+=a;
        for(int i=1;i<=a;i++)s+=c;
    }
    for(long long i=0;i<=(su-1)/2+(su-1)%2;i++){
        if(s[i]!=s[su-i-1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
//68 pts maybe
//I'm qu, big qu
