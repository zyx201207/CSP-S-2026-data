#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
long long a[maxn],cf[maxn],pre[maxn];
long long m;
int cmp=0,sub1 =0;
int main(){
    /*example:
    5 5
    1 2 4 8 9
    */
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    memset(cf,0,sizeof(cf));
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cf[i] = a[i]-a[i-1];
        if(a[i]==i){
            cmp++;
        }
    }
    sort(a,a+n+1);//n*cf[i]
    long long bj = a[2]-a[1];
    for(int i=2;i<=n;i++){
        cf[i] = a[i]-a[i-1];
        if(bj==cf[i]){
            sub1++;
        }
    }
    if(sub1 ==n-1){
        if((long long)n*(n-1)*bj/2 +n*a[1]<=m){
            cout << n;
            return 0;
        }
        for(int i=n-1;i>=1;i--){
            if((long long)i*(i-1)*bj/2 +i*bj<=m&&(long long)(i+1)*i*bj/2+(i+1)*bj>m){
                cout << i+1;
                return 0;
            }
        }
    }
    if(cmp ==n){
        if((long long)n*(n+1)/2 <=m){
            cout << n;
            return 0;
        }
        for(int i=n-1;i>=1;i--){
            if((long long)i*(i+1)/2 <=m&&(long long)(i+1)*(i+2)/2>m){
                cout << i+1;
                return 0;
            }
        }
    }
    long long ans =1,dj=0,sc=1;
    for(int i=1;i<=n;i++){
        if(i>=2){
            dj +=(long long)(i-1)*cf[i];
            if(dj<=m){
                ans++;
            }else{
                cout<< ans<<endl;
                return 0;
            }
        }
        

    }
    
}