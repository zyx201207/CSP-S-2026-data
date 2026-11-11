#include<bits/stdc++.h>
using namespace std;
string b[200005],ans;
int m,n;
long long a[200005],maxn=-1,a1=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int i=0;
    while(i<m){
        int y=1,x=2;
        while(x<=a[n-i]){
            x*=2;
            y++;
        }
        maxn=max(maxn,y);
        for(int j=y;j>=1;j--){
            if(x<a[n-i]){
                a[n-i]-=x;
                x/=2;
                b[n-i][j]='1';
            }
        }
        i++;
    }
    for(int i=1;i<=maxn;i++){
        ans[i]='1';
        for(int j=0;j<m;j++){
            if(b[n-j][i]=='0')ans[i]='0';
        }
        int f+=(ans[i]-'0');
        for(int j=i;j<=maxn;j++){
            f*=2;
        }
        a1+=f;
    }
    cout<<a1;
    return 0;
}
