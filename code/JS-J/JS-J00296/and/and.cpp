#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
const int MAXN=200005;

int n,m,fin,x[MAXN];
string ans,s[MAXN];
void sep(int n,int i){
    string t;
    while(n>0){
        t+=(n%2+'0');
        n/=2;
    }
    int y=t.size();
    for(int i=y+1;i<=31;i++) t+='0';
    reverse(t.begin(),t.end());
    s[i]=t;
}
bool cmp(string a,string b){
    return a>b;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+n+1);
    reverse(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        sep(x[i],i);
    }
    //for(int i=1;i<=n;i++) cout<<s[i]<<endl;
    int bas=1;
    /*while(x[bas]>=2*x[bas+1] && bas<=n-m){
        bas++;
    }
    cout<<bas<<endl;*/
    for(int i=0;i<31;i++){
        bool f=1;
        for(int j=bas;j<=bas+m-1;j++){
            if(s[j][i]=='0'){
                f=0;
                break;
            }
        }
        if(f) ans+='1';
        else ans+='0';
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<31;i++){
        fin+=(ans[i]-'0')*pow(2,i);
    }
    cout<<fin;
    return 0;
}

//id:JS-J00296
//This is the code of and.
//at least 10 pts(6,7)
//1,2,4 samples correct.
//3,5 samples wrong.
//Last modified on Oct.31st 11:45
//password:Trick||Treat!
