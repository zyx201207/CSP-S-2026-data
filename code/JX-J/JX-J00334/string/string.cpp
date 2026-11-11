#include<bits/stdc++.h>
using namespace std;
long long cnt,l,n,x,ln[222222];
int mn[222222];
string s;
char m;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>x>>m;
    l+=x;
    ln[i]=x;
    mn[i]=int(m);



}
long long nl=l/2;
int i=0;
int now=1;
int last=n;
while(now<last){
    if(ln[now]<=ln[last]){
        ln[last]-=ln[now];

if(mn[now]!=mn[last]){
    cnt+=ln[now];
    i+=ln[now];
}
ln[now]=0;
now++;
if(ln[last]==0){
    last--;
}

    }
    else{
        ln[now]-=ln[last];
        if(mn[now]!=mn[last]){
            cnt+=ln[last];
            i+=ln[last];
        }
        ln[last]=0;
        last--;

    }

}
cout<<cnt;



return 0;
}
