#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200100],ans;
char b[200100];
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    long long y=s.size()-1;
    if(s.size()%2==1){
//            cout<<5<<' ';
        for(int i=0;i<=s.size()/2;i++){
            if(s[i]!=s[i+y]){
   //             cout<<s[i]<<' '<<s[i+y]<<' '<<i<<' '<<y;
                ans++;
            }
            y-=2;
        }
        cout<<ans;
    }else{
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[i+y]){
                ans++;
            }
            y-=2;
        }
        cout<<ans;
    }
    return 0;
}
