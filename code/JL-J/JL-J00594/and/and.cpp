#include<bits/stdc++.h>
using namespace std;
int a[100000];
long long n,m;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++)
    cin>>a[i];
if(m==1){
    sort(a+1,a+n);
    cout<<a[n-1];
}
if(m==2){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if((a[i]&a[j])>ans) ans=a[i]&a[j];
    }
    cout<<ans;
}
if(m==n){
    int ans=a[0];
    for(int i=1;i<n;i++)
       ans=ans&a[i];
    cout<<ans;
}
fclose(stdin);
fclose(stdout);
return 0;
}
