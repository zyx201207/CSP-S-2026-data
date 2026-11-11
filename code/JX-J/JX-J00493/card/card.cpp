#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    bool p;
    int w;
}a[300002];
int b[300002],ans[300002],n,m,s,i,j,w,o;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(i<n){
        cin>>s;
        if(!a[s].p){
            a[s].p=true;
            w++;
            b[w]=s;
            a[s].w=w;
        }
        else{
            o=w+1;
            w=a[s].w-1;
            j=a[s].w;
            while(j<=w){
                a[b[j]].p=false;
                j++;
            }
        }
        j=1;
        while(j<=w){
            ans[b[j]]++;
            j++;
        }
    }
    i=1;
    while(i<n){
        cout<<ans[i];
        if(ans[i]!=n-1) cout<<" ";
        i++;
    }
    return 0;
}
