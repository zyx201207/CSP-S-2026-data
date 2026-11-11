#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
int n,l=1;
long long yu,cnt,ans,sum,mid;
struct node{
    long long num;
    char c;
}f[N];
char yl;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i].num>>f[i].c;
        mid+=f[i].num;
    }
    if(mid<=100000000){
        string s=" ";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=f[i].num;j++) s+=f[i].c;
        }
        for(int i=1;i*2<=mid;i++){
            if(s[i]!=s[mid-i+1]) cnt++;
        }
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans++;
        if(i==n-l+1) break;
        if(yu){
            if(f[i].num<=yu){
                if(f[i].c!=yl) cnt+=f[i].num;
                yu-=f[i].num;
                if(!yu) l++;
                continue;
            }
            else {
                if(f[i].c!=yl) cnt+=yu;
                f[i].num-=yu;
                yu=0,l++;
            }
        }
        if(i==n-l+1) break;
        if(f[i].num){
            if(f[i].num>=f[n-l+1].num){
                if(f[n-l+1].c!=f[i].c) cnt+=f[n-l+1].num;
                f[i].num-=f[n-l+1].num;
                yl=f[n-l+1].c;
                i--,l++;
            }
            else {
                if(f[n-l+1].c!=f[i].c) cnt+=f[i].num;
                yu=f[n-l+1].num-f[i].num;
                yl=f[n-l+1].c;
            }
        }
    }
    cout<<cnt;
    return 0;
}
