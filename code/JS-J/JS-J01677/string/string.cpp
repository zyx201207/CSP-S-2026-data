#include<bits/stdc++.h>
using namespace std;
int x=0,y=0,p,q;
char xt,yt;
long long n,s1=0,s2=0;
long long h;
char k[200005];
int a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>k[i];
        h+=a[i];
    }
    q=n;p=1;xt=k[1];yt=k[n];
    for(int i=1;i<=(h+1)/2;i++){
        x++;y++;
        if(x>0){
            x-=a[p];
            xt=k[p];
            p++;
        }
        if(y>0){
            y-=a[q];
            yt=k[q];
            q--;
        }
        if(xt!=yt) s1++;
    }
    for(int i=(h+1)/2+1;i<=h;i++){
        x++;y++;
        if(x>0){
            x-=a[p];
            xt=k[p];
            p++;
        }
        if(y>0){
            y-=a[q];
            yt=k[q];
            q--;
        }
        if(xt!=yt) s2++;
    }
    cout<<min(s1,s2);
    return 0;
}
