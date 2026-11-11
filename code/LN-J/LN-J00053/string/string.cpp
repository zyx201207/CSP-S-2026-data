#include<bits/stdc++.h>
using namespace std;

struct ttt{
    long long l,r;
    char c;
};
ttt u[200005];
ttt v[200005];
long long n,k,ans;
int main(){
    #define int long long
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int s;
        cin>>s>>u[i].c;
        u[i].l=k+1;
        k+=s;
        u[i].r=k;
    }
    int t;
    if(k%2==0)
        t=k/2+1;
    else
        t=k/2+2;
    ans=k-t+1;
    int i=1;
    while(1){
        int x=u[i].l,y=u[i].r;
        v[i].r=k-x+1,v[i].l=k-y+1,v[i].c=u[i].c;
        if(v[i].l<=t){
            v[i].l=t;
            break;
        }
        i++;
    }
    int m=i;
    i=1;
    int j=n;
    while(i<=m){
        if(v[i].c==u[j].c){
            if(u[j].r-u[j].l+1>v[i].r-v[i].l+1){
                ans-=(v[i].r-v[i].l+1);
                u[j].r=v[i].l-1;
                i++;
            }
            else{
                ans-=(u[j].r-max(u[j].l,t)+1);
                v[i].r=u[j].l-1;
                j--;
            }
        }
        else{
            if(u[j].r-u[j].l+1>v[i].r-v[i].l+1){
                u[j].r=v[i].l-1;
                i++;
            }
            else{
                v[i].r=u[j].l-1;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
