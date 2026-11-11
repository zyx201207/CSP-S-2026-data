#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n>>m;
int a[n+1]={0},b[m+1]={0},ans[m+1]={0};
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
for(long long i=1;i<=n;i++){
    for(long long j=i;j<=n;j++){
        if(b[a[i]]==0){ b[a[i]]=1;
        cout<<a[i]<<b[a[i]]<<endl;}
        else{
            for(long long k=1;k<=m;k++)
                b[k]=0;
            b[a[i]]=1;
            cout<<a[i]<<b[a[i]]<<endl;
        }
    }
    for(long long j=1;j<=m;j++){
        if(b[j]>0) {ans[j]++;
        }
    }
}
for(long long i=1;i<=m;i++)
    cout<<ans[i]<<" ";
fclose(stdin);
fclose(stdout);
return 0;
}
