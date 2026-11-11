#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //cout<<a[i]<<' '<<c[i]<<endl;
    }
    int gong=0;
    for(int i=1;i<=n;i++){
        gong+=a[i];
    }
    //cout<<"gong"<<gong<<endl;
    long long s_=0;
    long long a_=1;
    long long c_=1;

    for(int i=1;i<=n;i++){
        //cout<<c[c_]<<endl;
        while(a[a_]--){
            s[s_]=c[c_];
            s_++;
    //        cout<<1<<endl;
        }

        c_++;
        a_++;
    }
    long long ans=0;/*
    for(int i=0;i<gong;i++){
        cout<<s[i];
    }
*/
   // cout<<endl;
    for(int i=0;i<gong/2;i++){
        if(s[i]!=s[gong+1-i]){

            ans++;
            //cout<<"i"<<i<<' '<<"s[i]"<<s[i]<<' '<<"s[n+1-i]"<<s[n+1-i];
        }
        else continue;
    }
    cout<<ans;
    return 0;
}
