#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,id;
    long long m;
    cin>>n>>m;
    long long sum=0;
    int judge=1;


    for(int i=1;i<=n;i++){
        cin>>a[i];
        int s=abs(a[i]-a[i-1]);
        if(sum+(i-1)*s<=m){
            sum+=(i-1)*s;
            id=i;
        }
        if(i>2 && a[i-2]-a[i-1]!=a[i-1]-a[i])
            judge=0;
    }
    if(judge){
        cout<<id;
        return 0;
    }


    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        int num=1,l=i-1;
        sum=0;
        while(l>0){
            long long sl=a[i]-a[l];
            if(sum+sl<=m){
                sum+=sl;
                num++;
                l--;
            }
            else
                break;

        }
        ans=max(ans,num);
    }
    cout<<ans<<endl;

    return 0;
}

