#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct l{
long long c;
string b;
}d[200010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>n;
for(long long i=1;i<=n;i++){
    cin>>d[i].c>>d[i].b;
}
long long i=1,j=n;
while(i<j){
    if(d[i].b!=d[j].b){
        ans+=min(d[i].c,d[j].c);
    }
    if(d[i].c>d[j].c){
            d[i].c-=d[j].c;
            j--;
    }
    else if(d[i].c<d[j].c){
        d[j].c-=d[i].c;
        i++;
    }
    else {
        i++;
        j--;
    }
}
cout<<ans;
return 0;
}
