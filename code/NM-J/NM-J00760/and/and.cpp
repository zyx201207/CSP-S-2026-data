#include<bits/stdc++.h>
using namespace std;
int a[1000];
int abc(a,b){
    long long q,w,x[1000],s=0,y=0,d=1;
    while(1){
        if(a==0 and b==0) break;
        q=a%2;
        w=b%2
        s++;
        if(a==1 and b==1) x[s]=1
        else x[s]=0;
        a=(a-a%2)/2;
        b=(b-b%2)/2;
    }
    for(int i=1;i<=s;i++){
        y=y+x[i]*d;
        d=d*2;
    }
    return y;
}
int main(){
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
    long long m,n,ss=-1,j,k;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(j){
           j=m;
           k=abc(a[i],k);
           j--;
        }
        if(ss<k) ss=k;
    }
    cout<<ss;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
