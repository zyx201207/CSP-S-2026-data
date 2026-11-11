#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],s[500005];
long long res;
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    while(res<=m){
        ans++;
        res=a[ans]*(ans-1)-s[ans-1];
    }
    printf("%d",ans-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
