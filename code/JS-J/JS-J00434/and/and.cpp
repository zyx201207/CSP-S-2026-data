#include<bits/stdc++.h>
using namespace std;
int n,m;
const long long N=2e15;
long long a[200010];
string s[200010];
int b[200010][31];
int c[31];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        long long l=a[i];
        for(int j=0;j<30;j++){
            if(l%2==0) s[i]=s[i]+'0';
            else s[i]=s[i]+'1';
            l/=2;
        }
    }
    int t=n;

    for(int j=29;j>=0;j--){
        int k=t;
        for(int i=1;i<=n;i++){
            b[i][j]=b[i][j+1];
            if(b[i][j]==1) continue;
            if(s[i][j]=='0'){
                b[i][j]=1;
                k--;
            }
        }
        if(k<m){
            for(int i=1;i<=n;i++){
                if(b[i][j+1]==0) b[i][j]=0;
            }
        }
        else t=k;
    }
    t=m;
    long long ans=0;
    long long cnt=1;
    for(int i=1;i<=n;i++){
        if(b[i][0]==0){
            for(int j=0;j<30;j++){
                if(c[j]!=0 || s[i][j]=='0') c[j]=1;
            }
            t--;
            if(t==0) break;
        }
    }
    for(int i=0;i<30;i++){
        if(c[i]==0){
            ans+=cnt;
        }
        cnt*=2;
    }
    cout<<ans<<"\n";
    return 0;
}
