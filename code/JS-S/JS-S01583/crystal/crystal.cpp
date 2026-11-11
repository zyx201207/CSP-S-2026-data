#include<bits/stdc++.h>
using namespace std;
struct num{
int v;
int c;
}b[500005];
int cmp(num a,num b){
    return a.c>b.c;
}
long long  n,m,l=1,ans=0;
long long a[500005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>n>>m;
int cnt=0;
bool q=0;
for(int i=1;i<=n;i++){
    cin>>a[i];
    q=0;
    for(int j=1;j<l;j++){
        if(b[j].v==a[i]){
            b[j].c++;
            l++;
            q=1;
            break;
        }
    }
    if(q==0){
    b[l].v=a[i];
    b[l].c++;
    l++;
    }
}
sort(b+1,b+l,cmp);
for(int i=1;i<=n;i++){
    a[i]-=b[1].v;
}
sort(a+1,a+n+1);
for(int i=1;i<=n;i++){
    if(abs(a[i])<=m&&a[i]<=0){
        ans++;
        m+=a[i];
    }
    else break;
}
long long an=0;
while(m>0){
    for(int i=1;(a[i]==a[i-1]||i==1)&&m>0;i++){
        a[i]++;
        m--;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]||i==1)an++;
    }
    ans=max(an,ans);
}
cout<<ans;
return 0;
}
