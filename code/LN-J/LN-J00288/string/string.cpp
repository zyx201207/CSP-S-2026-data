#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T;
int a[N];
string s;
int siz=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--){
        int x;
        cin>>x;
        char c;
        cin>>c;
        a[siz]=x;
        siz++;
        s=s+c;
    }
    if(T==1){
        cout<<0;
    }
    else if(T==2){
        if(s[0]==s[1])cout<<0;
        else cout<<min(a[1],a[2]);
    }
    else{
        int L=0,R=s.size()-1;
        long long ans=0;
      while(L!=R){
        if(s[L]==s[R]){
            if(a[L+1]>a[R+1]){
                a[L+1]-=a[R+1];
                R--;

            }
            else{
                a[R+1]-=a[L+1];
                L++;

            }
        }
        else{
             ans+=min(a[L+1],a[R+1])*1ll;
             if(a[L+1]>a[R+1]){
                a[L+1]-=a[R+1];
                R--;
            }
            else{
                a[R+1]-=a[L+1];
                L++;

            }

        }
      }
      cout<<ans;
    }
    return 0;
}
