#include<bits/stdc++.h>
using namespace std;
#define ll long long
string repeat(char x,int times){
    string res="";
    for(int i=0;i<times;i++){
        res+=x;
    }
    return res;
}
int main(){
    //freopen("/home/user/Desktop/string/string1.in","r",stdin);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    ll total=0;
    string s="";
    for(int i=0;i<n;i++){
        int a;char c;
        cin>>a>>c;
        total+=a;
        s+=repeat(c,a);
    }
    ll mid=total/2;
    ll cnt=0;
    for(ll i=0;i<mid;i++){
        if(s[i]==s[total-i-1]){
            continue;
        }else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
