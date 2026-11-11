#include<bits/stdc++.h>
using namespace std;
struct node{
long long x;
char s;
};
node a[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string .out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i].x;
    cin>>a[i].s;
}
int l=1;
long long ls=a[1].x;
int r=n;
long long rs=a[n].x;
long long  ans=0;
while(l!=r){
    if(ls>rs){
        if(a[l].s!=a[r].s){
            ans+=rs;
        }
        ls=ls-rs;
        r=r-1;
        rs=a[r].x;
    }
    else if(rs>ls){
        if(a[l].s!=a[r].s){
            ans+=ls;
        }
        rs=rs-ls;
        l=l+1;
        ls=a[l].x;
    }
    else{
        if(a[l].s!=a[r].s){
            ans+=ls;
        }
        l++;
        ls=a[l].x;
        r--;
        rs=a[r].x;
    }
}
cout<<ans;
return 0;
}
