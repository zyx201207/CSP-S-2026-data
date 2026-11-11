#include<bits/stdc++.h>
using namespace std;
int n,m,t1;
long long s[200010],t[200010][2];
bool a[32],b[32];
long long ma(long long a,long long b){
    if(a<b)return a;
    else return b;
}
int main(){
    freopen("and","r",stdin);
    freopen("and","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(m==1){
        sort(s,s+n);
        cout<<s[n-1];
        return 0;
    }
    if(m==n-1||m==n){
        cout<<0;
    }
    for(int i=0;i<n-1;i++){
        int x=0;
        long long w;
        w=s[i];
        while(w>0){
            a[x]=w%2;
            w=w/2;
            x++;
        }
        for(int o=i+1;o<n;o++){
            x=0;
            long long w1;
            w1=s[o];
            while(w1>0){
                b[x]=w1%2;
                w1=w1/2;
                x++;
            }

        int u=0;
        for(int p=0;p<=30;p++){
            if(a[p]==b[p]&&a[p]==1){
                u=1;
                break;
            }
        }
        if(u==1){
            t[t1][0]=s[i];
            t[t1][1]=s[o];
            t1++;
        }
        }
    }
    long long j=0;
    for(int i=0;i<t1;i++){
        if(j<ma(t[i][0],t[i][1]))j=ma(t[i][0],t[i][1]);
    }
    cout<<j;
    return 0;
}
