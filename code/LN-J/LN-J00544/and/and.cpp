#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool b[200005][30];
int c[30];
int d[30];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long t=a[i];
        for(int j=1;j<=29;j++){
            b[i][j]=t%2;
            t/=2;
        }
    }
    int i,f=1,s=n;
    for(i=29;i>=1;i--){
        int c=0;
        for(int j=f;j<=s;j++){
            if(b[j][i]) c++;
        }
        if(c==m) break;
        else if(c>m){
            for(int k=1;k<=n;k++){
                if(b[k][i]){
                    f=k;
                    s=f+c-1;
                    break;
                }
            }
        }
    }
    long long x,p=0;;
    for(int k=f;k<=s;k++){
        if(b[k][i]){
            p++;
            if(p==1) x=a[k];
            else x=x&a[k];
        }
    }
    cout<<x;
    return 0;
}

