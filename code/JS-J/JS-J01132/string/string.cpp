#include<bits/stdc++.h>

using namespace std;
long long a[200005],fa[200005],lst[200005],flst[200005];
char c[200005],fc[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        lst[i]=lst[i-1]+a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++) fa[i]=a[n-i+1],fc[i]=c[n-i+1],flst[i]=flst[i-1]+fa[i];
    //long long tool=sum/2;

    long long ans=0,flag=1;
    for(int i=1,j=1;i<=n;i++){
        while(flst[j]<=lst[i]){
            if(j>n){
                flag=0;
                break;
            }
            if(fc[j]!=c[i]) ans+=fa[j];
            j++;
        }
        if(!flag) break;
        long long t=lst[i]-flst[j-1];
        fa[j]-=t;
        if(fc[j]!=c[i]) ans+=t;
        //if(lst[i+1]>=tool) break;
    }
    cout<<(ans+1)/2;
    return 0;
}
