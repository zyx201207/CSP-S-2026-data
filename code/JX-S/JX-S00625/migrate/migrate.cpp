#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define unsigned long long
#define PII pair<int,int>
const int N=2e6+10;
int mp[N];
int n,d;
string add1(string s,int a){
    if(a==0) return s+"0";
    if(a==1) return s+"1";
    if(a==2) return s+"2";
    if(a==3) return s+"3";
    if(a==4) return s+"4";
    if(a==5) return s+"5";
    if(a==6) return s+"6";
    if(a==7) return s+"7";
    if(a==8) return s+"8";
    if(a==9) return s+"9";
}
string add2(string s,int a){
    if(a==0) return "0"+s;
    if(a==1) return "1"+s;
    if(a==2) return "2"+s;
    if(a==3) return "3"+s;
    if(a==4) return "4"+s;
    if(a==5) return "5"+s;
    if(a==6) return "6"+s;
    if(a==7) return "7"+s;
    if(a==8) return "8"+s;
    if(a==9) return "9"+s;
}
bool check(int st,int en){
    string s1=add1("",st),s2=add1("",en);
    for(int i=st;i<en;){
        int p=upper_bound(mp+i,mp+en+1,mp[i]+d)-mp-1;
        if(p==i) return false;
        i=p;
        s1=add1(s1,p);
    }
    for(int i=en;i>st;){
        int p=lower_bound(mp+st,mp+i+1,mp[i]-d)-mp;
        if(p==i) return false;
        i=p;
        s2=add2(s2,p);
    }
    cout<<s1<<" "<<s2<<'\n';
    if(s1!=s2) return true;
    return false;
}
int main(){
    IOS;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>mp[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
