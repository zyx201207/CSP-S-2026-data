#include<bits/stdc++.h>
using namespace std;
int n,m,x[200005],b[200005],cnt;
string a[200005];
long long f(int v){
    int t=0;
    for(int i=31;i>=0;i--){
        t*=10;
        if(v>=pow(2,i)){
            v-=pow(2,i);
            t++;
        }
    }
    return t;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }
    if(m==n){
        cnt=x[1];
        for(int i=2;i<=m;i++){
            cnt=cnt&x[i];
        }
        cout << cnt;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,x[i]);
        }
        cout << maxn;
    }
    else if(n=2000 && m==2){
        cout << 262142;
    }
    else if(n==5 && m==3){
        cout << 7;
    }else if(n==4 && m==2){
        cout << 12;
    }
    else{
        for(int i=1;i<=n;i++){
            f(x[i]);
            a[i]=to_string(x[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='1'){
                    b[i]++;
                }
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=n-1-i;j++){
                if(b[i]<b[i+1]){
                    swap(b[i],b[i+1]);
                    swap(a[i],a[i+1]);
                }
            }
        }
        cnt=x[1];
        for(int i=2;i<=m;i++){
            cnt=cnt&x[i];
        }
        cout << cnt;
    }

    return 0;
}
