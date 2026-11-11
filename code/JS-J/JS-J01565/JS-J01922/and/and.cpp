#include<bits/stdc++.h>
using namespace std;
#define gg long long

const int N=2e5+10;
int n,m;
int a[N];
vector<int> vect[35];
unordered_map<int,bool> mp[35];
string s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn=-1;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    for(int tot=1;tot<=32;tot++){
        for(int i=1;i<=n;i++){
            if(a[i]&1){ mp[tot][i]=true;vect[tot].push_back(i);}
            a[i]>>=1;
        }
    }
    bool flag=false;
    int id;
    for(int tot=32;tot>=1;tot--){
        if(mp[tot].size()>=m){
            if(!flag){
                id=tot;
                // cout<<tot<<' '<<id<<'\n';
                s+='1';
                flag=true;
            }else{
                int flag2=true;
                for(int val:vect[id]){
                    if(!mp[tot][val]) {
                        flag2=false;
                        break;
                    }
                }
                if(flag2){
                    id=tot;
                    s+='1';
                }else{
                    s+='0';
                }
            }
        }else if(flag){
            s+='0';
        }
    }
    gg ans=0;
    gg n2=1;
    int tot=s.size();
    while(1){
        if(tot==0) break;
        if(s[tot-1]=='1') ans+=n2;
        n2*=2;
        tot--;
    }
    cout<<ans;
    return 0;
}