#include<bits/stdc++.h>
using namespace std;
long long n;
long long a;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long  i=1;i<=n;i++){
        cin>>a>>c;
        while(a--)s+=c;
    }
    long long ans=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
//大数据过不了了
//刚才输了一个大数据把电脑搞炸了，键鼠失效（悲
//重启了
//默哀awa
