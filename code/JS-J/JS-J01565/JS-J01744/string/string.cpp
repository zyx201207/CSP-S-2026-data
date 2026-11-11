#include<bits/stdc++.h>
const int N=2e5+10;
using namespace std;
long long n,m;
string s,v;
long long l,r;
int a[N],sum,cnt;
char t[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        a[i]=m;
        sum+=a[i];
        char c;
        cin>>c;
        t[i]=c;
        for(int i=0;i<m;i++){
            s+=c;
        }

    }
    v=s;
    reverse(s.begin(),s.end());
    if(s==v){
        cout<<0;
        return 0;
    }else{
        l=0;
        r=sum-1;
        while(l<r){
            if(s[l]!=s[r]) cnt++;
            l++;
            r--;
        }
        cout<<cnt;
    }
    return 0;

}
