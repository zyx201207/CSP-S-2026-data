#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define cspj std;
iwill ak cspj
struct node{
    int a;
    char c;
}f[300005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i].a>>f[i].c;
    }
    long long ans=0;
    for(int i=1,j=n;i<j;){
        if(f[i].c==f[j].c){
            if(f[i].a>=f[j].a){
                f[i].a-=f[j].a;
                f[j].a=0;
            }
            if(f[j].a>=f[i].a){
                f[j].a-=f[i].a;
                f[i].a=0;
            }
            if(f[i].a==0){
                i++;
            }
            if(f[j].a==0){
                j--;
            }
        }
        else{
            if(f[i].a>=f[j].a){
                f[i].a-=f[j].a;
                ans+=f[j].a;
                f[j].a=0;
            }
            if(f[j].a>=f[i].a){
                f[j].a-=f[i].a;
                ans+=f[i].a;
                f[i].a=0;
            }
            if(f[i].a==0){
                i++;
            }
            if(f[j].a==0){
                j--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}/////////
