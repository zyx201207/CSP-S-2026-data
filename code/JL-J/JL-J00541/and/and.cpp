#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx3=-1;
string ge[25];
long long cunchu[23][23];
void dfs(int yijing,int have,long long zhi){
    if(have==m){
            mx3=max(mx3,zhi);
            return ;
    }
    dfs(yijing+1,have+1,zhi&a[yijing]);
    dfs(yijing+1,have,zhi);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long mx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    else if(m==2){
        long long mx2=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx2=max(mx2,a[i]&a[j]);
            }
        }
        cout<<mx2;
        return 0;
    }
    else if(m==n){
        long long shi=a[1];
        for(int i=1;i<=n;i++){
            shi&=a[i];
        }
        cout<<shi;
        return 0;
    }
    else if(n<=10){
        for(int i=1;i<=n;i++){
            dfs(1,1,a[i]);
        }
        cout<<mx3;
        return 0;
    }

    else if(n<=20){
        for(int i=1;i<=n;i++){
            string s="";
            int t=a[i];
            while(t!=0){
                    int x=a[i]%2+48;
                s=char(x)+s;
                t/=2;
            }
            ge[i]=s;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i==j) continue;
                int l=ge[i].size()-1;
                int cnt=0;
            int r=ge[j].size()-1;
            int o=0;
            while(l>=0&&r>=0){
                    if(ge[i][l]==ge[j][r] )cnt+=pow(2,o);
                    o++;
            }
            cunchu[i][j]=cnt;
            }
        }
        int mx3=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    mx3=max(mx3,min(cunchu[i][j],min(cunchu[i][k],cunchu[j][k])));
                }
            }
        }
cout<<mx3;
    }
    return 0;
}
