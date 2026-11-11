#include <bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
int n;
struct zh{
    long long num;
    char c;
}a[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    char cur1,cur2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].c;
    }
    string s;
    for(int i=0;i<n;i++){
        for(int i=0;i<a[i].num;i++){
            s+=a[i].c;
        }
    }
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]!=s[l-1-i]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
