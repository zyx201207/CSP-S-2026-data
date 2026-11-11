#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c[500001];
int f(int p){
    int ans=1;
    long long tmp=m,node=c[p];
    for(int i=p+1;i<=n;i++){
        if((c[i]-node)*(i-p)>tmp)return ans;
        else{
            ans++;
            tmp-=(c[i]-node)*(i-p);
            node=c[i];
        }
    }
    return ans;

}bool flag=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]>2&&c[i]-c[i-1]!=c[i-1]-c[i-2])flag=0;
    }
    sort(c+1,c+n+1);
    if(flag){
        long long pass=c[2]-c[1],node;
        node=pass;
        for(int i=1;i<=n;i++){
            if(m-node>0){
                m-=node;
                ans++;
                node+=pass;
            }else break;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,f(i));
    }
    cout<<ans;
    return 0;
}
/*int main(){

    freopen("crystal3.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    int h=1;
    long long cost=0;
    int ans=1;
    for(int e=2;e<=n;e++){
        cost+=(c[e]-c[e-1])*(e-h);
        while(cost>m){
            cost-=(c[h+1]-c[h])*(e-h);
            h++;
        }
        ans=max(ans,e-h+1);
    }
    cout<<ans;
}*/
