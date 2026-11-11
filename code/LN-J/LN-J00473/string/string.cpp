#include<bits/stdc++.h>
using namespace std;
int n,a[200100];
long long ans=0,s[200200],mid;
char c[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
    }
    mid=s[n]/2;
    int ix=0,jx=s[n];
    for(int i=1,j=n-1;;){
        int x=s[i]-ix;
        int y=jx-s[j];
        if(x<y){
            if(c[i]!=c[j+1])ans+=x;
            ix=s[i];
            jx-=x;
            i++;
        }else if(x>y){
            if(c[i]!=c[j+1])ans+=y;
            jx=s[j];
            ix+=y;
            j--;
        }else{
            if(c[i]!=c[j+1])ans+=x;
            ix=s[i];
            jx=s[j];
            i++,j--;
        }
        if(i>j)break;
    }
    cout<<ans;
    return 0;
}
