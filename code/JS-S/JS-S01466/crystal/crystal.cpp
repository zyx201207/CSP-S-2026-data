#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a1,int a2){
    return a1>a2;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,bj;
    long long m,m1,maxn,ans=1,ans1=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    maxn=a[0];
    m1=m;
    bool judge=true;
    for(int i=0;i<n;i++){
        if(a[i]==maxn){
            ans1+=1;
            continue;
        }
        else if(judge){
            judge=false;
            bj=i;
        }
        if((maxn-a[i])<=m1){
            m1=m1-(maxn-a[i]);
            ans1+=1;
        }
        else{
            ans=max(ans,ans1);
            i=bj;
            if(n-i<=ans)break;
            i--;
            judge=true;
            m1=m;
            ans1=0;
            maxn=a[bj];
        }
    }
    ans=max(ans,ans1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
