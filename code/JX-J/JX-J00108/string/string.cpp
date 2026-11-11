#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9+10*2000;
long long n,x,t=0,cnt=0;
char y;
char a[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x>>y;
        while(x--){
             a[++t]=y;
        }
    }
    for(int i=1;i<=(t+1)/2;i++){
        if(a[i]!=a[t-i+1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
