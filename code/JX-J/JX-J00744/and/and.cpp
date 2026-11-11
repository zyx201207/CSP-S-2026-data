#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
const int N=2e5+10;
LL a[N];
string bin[N];
LL t[40];
LL lis[N][40];
bool vis[N];
bool cmp(LL x,LL y){
    return x>y;
}
LL l_max=-1;
string to_bin(LL x){
    string ans="";
    while(x){
        if(x%2==0) ans="0"+ans;
        else ans="1"+ans;
        x/=2;
    }
    if(l_max>0&&ans.length()<l_max){
        while(ans.length()<l_max){
            ans="0"+ans;
        }
    }
    return ans;
}
LL to_LL(string s){
    LL ans=0;
    for(LL i=0;i<l_max;i++){
        ans+=(s[i]-'0')*pow(2,l_max-1-i);
    }
    return ans;
}
int main(){
    IOS;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(LL i=1;i<=n;i++){
        bin[i]=to_bin(a[i]);
        if(i==1) l_max=bin[i].length();
    }
    for(LL i=1;i<=n;i++){
        for(LL j=0;j<bin[i].length();j++){
            if(bin[i][j]=='1'){
                t[j]++;
                lis[i][j]++;
            }
        }
    }
    string ans="";
    for(LL i=0;i<l_max;i++){
        if(t[i]>=m){
            for(LL j=1;j<=n;j++){
                if(bin[j][i]=='0'&&!vis[j]){
                    vis[j]=1;
                    for(LL k=i;k<l_max;k++){
                        t[k]-=lis[j][k];
                    }
                }
            }
            ans+="1";
        }else ans+="0";
    }
    cout<<to_LL(ans);
    return 0;
}
