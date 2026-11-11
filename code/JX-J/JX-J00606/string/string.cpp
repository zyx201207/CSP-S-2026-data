#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    string s5;
    s5=s;
    reverse(s5.begin(),s5.end());
    if(s5==s) return 1;
    else return 0;
}
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,x;
    string s,s1;
    cin>>n;
    int cnt=0;
    while(n--){
        cin>>x>>s;
        for(int i=1;i<=x;i++){
            s1=s1+s;
        }
    }
    int ans[10000005]={},num=1,sum=100000000;
    int pp=1;
    string m[30]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    for(int i=0;i<=s1.size()-1;i++){
        s1[i]=m[pp];
        pp++;
        ans[num]++;
        if(check(s)){
            num++;
        }
    }
    sort(ans+1,ans+1+num);
    cout<<ans[1];
    return 0;
}
