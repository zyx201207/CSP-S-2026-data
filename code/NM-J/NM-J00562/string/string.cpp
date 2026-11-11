#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt[25];
struct a{
    long long m;
    string s;
}c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].m>>c[i].s;
    }
    int l=1;
    int r=n;
    while(l<r){
        if(c[l].s!=c[r].s){
            cnt[1]+=min(c[l].m,c[r].m);
        }
        int j=1;
        while(cnt[j]!=0){
            cnt[j+1]+=cnt[j]/10;
            cnt[j]%=10;
            j++;
        }
        int p=min(c[l].m,c[r].m);
        c[l].m-=p;
        c[r].m-=p;
        if(c[l].m==0) l++;
        if(c[r].m==0) r--;
    }
    int c1=1;
    for(int i=25;i>=1;i--){
        if(cnt[i]!=0) c1=0;
        if(c1) continue;
        cout<<cnt[i];
    }
}
