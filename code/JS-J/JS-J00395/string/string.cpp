#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s;
    ll n,a;
    char c;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>c;
        while(a>0){
       if(a>10000000){
            for(int j=0;j<10000;j+=100){
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                 s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;
                s+=c;

            }
            a-=10000000;
       }
        else{
            for(int j=0;j<a;j++){
                s+=c;
                a--;
            }
        }
        }

    }
    cout<<s<<endl;
    ll len,ans=0;
    len=s.size();
    //if(len%2!=0){
         ll mid=len/2;
         for(ll i=0;i<mid;i++){
            if(s[i]!=s[len-i-1]){
                ans+=1;
            }
         }
    //}
    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;

}
