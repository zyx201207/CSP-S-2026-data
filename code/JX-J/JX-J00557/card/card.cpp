#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[300005],s[300005],fw=1;
stack<long long>b;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) fw=0;
    }
    if(n<5001){
        for(int i=1;i<=n;i++){
            while(!b.empty()) b.pop();
            memset(f,0,sizeof(f));
            for(int j=i;j<=n;j++){
                if(!f[a[j]]) b.push(a[j]),f[a[j]]=1;
                else while(b.top()!=a[j]) f[b.top()]=0,b.pop();
            }
            for(int i=1;i<=m;i++) if(f[i]) s[i]++;
        }
        for(int i=1;i<=m;i++) cout<<s[i]<<' ';
        return 0;
    }
    if(m<3){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[n]) s[1]++,s[2]++;
            else s[a[n]]++;
        }
        cout<<s[1]<<' '<<s[2]<<endl;
    }
    if(fw){
        for(int i=1;i<=n;i++) f[a[i]]++;
        for(int i=1;i<=m;i++) f[i]+=f[i-1],cout<<f[i]<<' ';
        return 0;
    }
    return 0;
}
