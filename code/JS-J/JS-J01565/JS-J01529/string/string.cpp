#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s1;
int len;
int ans = 0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a>>c;
        len += a;
        for(int i=1;i<=a;i++){
            s1+= c;
        }
    }
   // cout<<s1<<endl;
   // cout<<len<<endl;
    string s2;
    for(int i=0;i<=len/2;i++){
        s2[i] = s1[len - 1 - i];
    }
    //cout<<s2<<endl;
    if(len & 1){
        int num = len / 2 - 1;
        int mid = len / 2;
        for(int i=0;i<=num;i++){
            if(s1[i] != s2[i]){
                ans++;
                //cout<<ans<<endl;
            }
        }
        if(s1[mid] != s2[mid]){
            ans++;
        }
    }else{
        int num = len / 2 - 1;
        for(int i=0;i<=num;i++){
            if(s1[i] != s2[i]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
