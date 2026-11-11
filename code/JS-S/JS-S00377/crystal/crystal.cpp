
#include<bits/stdc++.h>
using namespace std;
long long n,m,ok,maxn=-1,ans=1,rec;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=c)ok=1;
    }
    if(!ok){
        for(int i=1;i<=n;i++){
        m-=i*c;
        if(m<=0){
            cout<<i;
            return 0;
        }
    }
    }
    else{
        for(int i=1;i<=n-1;i++){
        if(a[i+1]>a[i]){
            if(m<=0)break;
            m-=i*(a[i+1]-a[i]);
            rec+=i*(a[i+1]-a[i]);
            ans++;
        }
        else{
            m+=rec;
            rec=0;
        }

    }
    cout<<ans;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
