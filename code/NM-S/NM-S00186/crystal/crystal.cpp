#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],ans=10000005,w=1,t,s,b;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
        for(int i=1;i<=n;i++){
        if(a[i]<ans){
            ans=a[i];
            t=i;
        }
    }
    for(int i=1;i<=m;i++){
        if(ans+=i==a[w]){
            m-=i;
            a[t]=ans+=i;
            break;
        }
        w++;
    }
    if(m==0){
        for(int i=1;i<=n;i++){
                b=a[i];
            for(int j=1;j<=n;j++){
                if(b==a[j])s+=1;
            }
        }
        cout<<s;
        break;
    }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
