#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    int a[1000000];
    long long t=0,k=1;
    long long ans=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]){
                t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
    if(a[1]>=0)
        for(int i=2;i<=n;i++){
            if(m>0&&m-((i-1)*(a[i]-a[i-1]))>=0){m=m-((i-1)*(a[i]-a[i-1]));ans++;}
            else {cout<<ans;return 0;}
        }

    if(a[1]<0){
        for(int i=1;i<=n;i++)
            a[i]=a[i]+(0-a[1]);
        for(int i=2;i<=n;i++){
            if(m>0&&m-((i-1)*(a[i]-a[i-1]))>=0){m=m-((i-1)*(a[i]-a[i-1]));ans++;}
            else {cout<<ans;return 0;}
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
