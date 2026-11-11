#include<bits/stdc++.h>
using namespace std;
string s[200005];
bool f[200005];
int t[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        int cnt=0;
        int u=t[i];
        while(u!=0){
            s[i]+=('0'+u%2);
            u/=2;
            cnt++;
        }
        for(int j=1;j+cnt<=30;j++){
            s[i]+='0';
        }
    }
    memset(f,1,sizeof(f));
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='1'&&f[j]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(s[j][i]=='0'){
                    f[j]=0;
                }
            }
        }
    }
    int p=1073741823;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i]){
            p&=t[i];
            cnt++;
        }
        if(cnt==m){
            break;
        }
    }
    cout<<p;
    return 0;
}
