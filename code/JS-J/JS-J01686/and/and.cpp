#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a;
long long ans;
char c[200005][35];
bool flag[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        string s;
        while(a!=0){
            int c=a%2;
            s+=char(c+'0');
            a/=2;
        }
        for(int j=0;j<=(32-s.size());j++){
            c[i][j]='0';
        }
        for(int j=32;j>=(32-s.size());j--){
            c[i][j]=s[32-j];
        }
   /*     for(int j=0;j<=32;j++){
            cout<<c[i][j];
        }
        cout<<"\n";*/
    }
    for(int i=0;i<=32;i++){
        int h=0;
        for(int j=1;j<=n;j++){
            if(c[j][i]=='1'&&flag[j]==0)h++;
        }
        if(h>=m){
            for(int j=1;j<=n;j++){
                if(c[j][i]=='0')flag[j]=1;
            }
        //    cout<<i<<' '<<32-i+1<<'\n';
            long long k=1;
            for(int j=1;j<=32-i;j++){
                k*=2;
            }
            ans+=k;
        }
    }
    cout<<ans;
    return 0;
}

