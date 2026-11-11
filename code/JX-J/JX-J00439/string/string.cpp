#include <bits/stdc++.h>
using namespace std;
struct s{
    long long sl;
    char zf;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;s st[n];
    for(int i=0;i<n;i++){
        cin>>st[i].sl>>st[i].zf;
    }
    long long q=0,h=n-1,num=0;
    while(q<=h){
        if(st[q].zf!=st[h].zf){
            long long aaa=min(st[q].sl,st[h].sl);
            st[q].sl-=aaa;st[h].sl-=aaa;num+=aaa;
        }else{
            long long aaa=min(st[q].sl,st[h].sl);
            st[q].sl-=aaa;st[h].sl-=aaa;
        }
        if(st[q].sl<=0){q++;}
        if(st[h].sl<=0){h--;}
    }
    cout<<num;
    return 0;
}

