#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
string a[N];
string binary(int x){
    string y;
    while(x){
        y.push_back((x&1)+'0');
        x>>=1;
    }
    return y;
}
bool cmp(string a,string b){
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int maxlen=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=binary(x);
        maxlen=max(maxlen,int(a[i].size()));
    }
    for(int i=1;i<=n;i++){
        while(a[i].size()<maxlen){
            a[i].push_back('0');
        }
        reverse(a[i].begin(),a[i].end());
    }
    for(int i=0;i<maxlen;i++){
        int cnt=0;
        vector<int>v;
        for(int j=1;j<=n;j++){
            if(a[j][i]-'0'){
                cnt++;
                v.push_back(j);
            }
        }
        if(cnt<m){
            for(auto j:v){
                a[j][i]='0';
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=0;i<maxlen;i++){
        int p=1;
        for(int j=1;j<=m;j++){
            p=p&(a[j][i]-'0');
        }
        ans=(ans<<1)|p;
    }
    cout<<ans;
    return 0;
}
