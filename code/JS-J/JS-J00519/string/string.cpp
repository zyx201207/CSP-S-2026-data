#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int n,s,t,ans;
int a[MAXN];
char c[MAXN];
vector<int> tl,tr,tv;
vector<char> cl,cr,al,ar;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    t=0;
    for(int i=1;i<=n;i++){
        if(t+a[i]>s/2){
            if(s/2-t){
                tl.push_back(s/2);
                cl.push_back(c[i]);
            }
        }
        else{
            t+=a[i];
            tl.push_back(t);
            cl.push_back(c[i]);
        }
    }
    t=0;
    for(int i=n;i>=1;i--){
        if(t+a[i]>s/2){
            if(s/2-t){
                tr.push_back(s/2);
                cr.push_back(c[i]);
            }
        }
        else{
            t+=a[i];
            tr.push_back(t);
            cr.push_back(c[i]);
        }
    }
    for(int i:tl)tv.push_back(i);
    for(int i:tr)tv.push_back(i);
    sort(tv.begin(),tv.end());
    tv.erase(unique(tv.begin(),tv.end()),tv.end());
    t=0;
    for(int i=0;i<(int)tl.size();i++)
        while(t<(int)tv.size()&&tv[t]<=tl[i]){
            al.push_back(cl[i]);
            t++;
        }
    t=0;
    for(int i=0;i<(int)tr.size();i++)
        while(t<(int)tv.size()&&tv[t]<=tr[i]){
            ar.push_back(cr[i]);
            t++;
        }
    for(int i=0;i<(int)tv.size();i++)
        if(al[i]!=ar[i]){
            if(i==0)ans+=tv[i];
            else ans+=tv[i]-tv[i-1];
        }
    cout<<ans;
    return 0;
}
//g++ string.cpp -o string -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576 && ulimit -s 1048576 && time ./string