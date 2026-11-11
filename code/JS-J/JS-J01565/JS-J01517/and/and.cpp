#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
int cnt,t,p;
int power(int x,int y){
    int e=1;
    while(y--){
        e*=x;
    }
    return e;
}
void s(int x,int y){
    int suma=0,num=0,w=0;
    while(x>0){
        num=num*10+x%2;
        x/=2;
        suma++;
    }

    while(num>0){
        w=w*10+num%10;
        num/=10;
    }
    b[y]=suma;
    c[y]=w;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s(a[i],i);
    for(int i=n;i>=i;i--){
        if(b[i]!=b[i+1]){
            if(t>=m){
                p=power(2,b[i+1]-1);

            }
            else{
            t=0;
            t++;
            }
        }
        else t++;

    }
    cout<<p;
    return 0;
}
