#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct str{
    ll x;
    char t;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n=0;
    cin>>n;
    str s[n];
    for(int i=0;i<n;i++){
        cin>>s[i].x>>s[i].t;
    }
    ll left=0;
    ll right=n-1;
    ll cnt=0;
    while(left<right){
        if(s[left].t!=s[right].t){
            if(s[left].x>s[right].x){
                cnt+=s[left].x-s[right].x;
                s[left].x-=s[right].x;
                s[right].x=0;
                right--;
            }else if(s[left].x<s[right].x){
                cnt+=s[right].x-s[left].x;
                s[right].x-=s[left].x;
                s[left].x=0;
                left++;
            }else{
                cnt+=s[left].x;
                s[right].x=0;
                s[left].x=0;
                left++;
                right--;
            }
        }else{
            if(s[left].x>s[right].x){
                s[left].x-=s[right].x;
                s[right].x=0;
                right--;
            }else if(s[left].x<s[right].x){
                s[right].x-=s[left].x;
                s[left].x=0;
                left++;
            }else{
                s[right].x=0;
                s[left].x=0;
                left++;
                right--;


        }
    }
    }

    cout<<cnt;
    return 0;
}
