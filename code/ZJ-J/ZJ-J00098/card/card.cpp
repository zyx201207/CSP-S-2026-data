#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long desk[500010];
long long t[300010];
long long cnt;
void left(long long fin){
    for(int i=1;i<=cnt;i++){
        if(desk[i]==fin){
            for(int j=i;j<=cnt;j++){
                desk[j]=0;
            }
            cnt=i-1;
            return;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            left(a[i]);
            desk[++cnt]=a[i];
        }
        for(int i=1;i<=cnt;i++){
            t[desk[i]]++;
        }
        cnt=0;
        memset(desk,0,sizeof(long long)*(n+1));
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
