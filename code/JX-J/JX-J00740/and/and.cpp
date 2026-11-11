#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn,b[200010],c[40],ans;
string s[200010];
struct node{
    int a,b;
    string s;
}r[200010];
string trans(int x,int y){
    string s1;
    int sum=0,q=x,w;
    while(q!=0){
        sum++;
        q/=2;
    }
    r[y].b=sum;
    for(int i=sum-1;i>=0;i--){
        w=pow(2,i);
        if(x>=w){
            s1+='1';
            x-=w;
        }else{
            s1+='0';
        }
    }
    return s1;
}
string buqi(string x,int y){
    string s1;
    for(int i=1;i<=(maxn-y);i++){
        s1+='0';
    }
    x=s1+x;
    return x;
}
bool cmp(node x,node y){
    return x.s>y.s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i].a);
        r[i].s=trans(r[i].a,i);
        maxn=max(maxn,r[i].b);
    }
    for(int i=1;i<=n;i++){
        if(r[i].b<maxn){
            r[i].s=buqi(r[i].s,r[i].b);
        }
    }
    for(int j=0;j<maxn;j++){
        for(int i=1;i<=n;i++){
            if(r[i].s[j]=='1') c[j]++;
        }
        if(c[j]>=m){
            for(int i=1;i<=n;i++){
                if(r[i].s[j]=='0'){
                    for(int k=0;k<maxn;k++) r[i].s[k]='0';
                }
            }
        }
    }
    sort(r+1,r+1+n,cmp);
    int ans=r[1].a;
    for(int i=2;i<=m;i++){
        ans&=r[i].a;
    }
    printf("%d",ans);
    return 0;
}
