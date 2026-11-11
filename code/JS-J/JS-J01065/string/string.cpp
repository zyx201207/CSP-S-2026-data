#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define Fr(i,l,r) for(int i=l;i<r;i++)
#define vec vector
#define vul vec<ull>
#define stop return 0
#define BEGIN ;
#define END return 0;
int main(){
    // basic settings
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // input
    ull n;
    cin>>n;
    vul cnt(n+5);
    vec<char> chr(n+5);
    if (n==1){
        cout<<0;
        return 0;
    }
    Fr(i,0,n){
        cin>>cnt[i];
        cin>>chr[i];
    }
    // main
    ull i=0,j=n-1,ans=0;
    while (i<j){
        ull i_len = cnt[i],
            j_len = cnt[j];
        ans+=min(i_len,j_len)*(chr[i]!=chr[j]);
        /*
        cout<<"i="<<i<<'\n';
        cout<<"j="<<j<<'\n';
        cout<<"ilen="<<i_len<<'\n';
        cout<<"jlen="<<j_len<<'\n';
        */
        if (i_len<j_len){
            i++;
            cnt[j]-=i_len;
        }else if(i_len>j_len){
            j--;
            cnt[i]-=j_len;
        }else{
            i++;
            j--;
        }
        /*
        cout<<"i="<<i<<'\n';
        cout<<"j="<<j<<'\n';
        cout<<"\n";
        */
    }
    cout<<ans;
    return 0;
}
