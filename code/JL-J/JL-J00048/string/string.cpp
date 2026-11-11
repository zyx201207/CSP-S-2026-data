#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    string s="";
    cin>>n;
    while(n--){
        long long tmp;
        char c;
        cin>>tmp>>c;
        while(tmp--){//xiao lv tai man hou mian huan
            s=s+c;
        }
    }
    long long ans=0;
    long long left=0,right=s.size()-1LL;
    while(left<=right){
        if(s[left]!=s[right])ans++;
        left++,right--;
    }
    cout<<ans<<'\n';
    return 0;
}
