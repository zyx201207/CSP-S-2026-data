#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    s="";
    cin>>n;
    long long num;
    char ch;
    for(int i=1;i<=n;i++){
        cin>>num>>ch;
        for(int i=1;i<=num;i++){
            s+=ch;
        }
    }
    //最少修改 将s改为回文
    long long len=s.length();
    long long ans=0;
    if(len%2==1){
        long long centre_pos=(1+len)/2-1;
        long long l=centre_pos-1;
        long long r=centre_pos+1;
        while(l>=0&&r<=len-1){
            if(s[l]!=s[r]){
                ans++;
            }
            l--;
            r++;
        }
    }
    if(len%2==0){
        long long l=(1+len)/2;
        long long r=l+1;
        while(l>=0&&r<=len-1){
            if(s[l]!=s[r]){
                ans++;
            }
            l--;
            r++;
        }
    }
    cout<<ans;
}
