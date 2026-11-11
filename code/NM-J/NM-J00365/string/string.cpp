#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0,r=0,ans=0,num=0;
    long long a[200005];
    char c[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
    }
    if(n<=2){
        if(c[0]==c[1] || n==1) cout<<0;
        else cout<<min(a[0],a[1]);
    }
    if(n>=3){
    r=num-1;
    for(int i=0;i<num/2;i++){
        if(a[l]==0) l+=1;
        if(a[r]==0) r-=1;
        if(c[l]!=c[r]){
            ans+=1;
            a[l]-=1;
            a[r]-=1;
        }
        else{
            a[l]-=1;
            a[r]-=1;
        }
    }
    cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
