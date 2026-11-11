#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m,b,mi=0,c,ans;
cin>>n>>m;
int a[n+1];
for(int i=0;i<n;i++){
    cin>>b;
    a[i]=b;
}
for(int i=0;i<n;i++){
    for(int j=n-1;j>=0;j++){
        if(a[j-1]>a[j]){
            swap(a[j-1],a[j]);
        }
    }
}
for(int i=0;i<n;i++){
    if(a[i]==a[i+1]){
        a[i]=a[i]*2;
        ans++;
        for(int j=i+1;j<n;j++){
            a[j]=a[j+1];
        }
    }
}
while(m){
   for(int i=0;i<n;i++){
    if(a[i]-a[i-1]<mi){
        c=i;
    }

   }
   while(a[c]-a[c-1]){
    a[c-1]++;
        m--;
        }
    for(int i=0;i<n;i++){
    if(a[i]==a[i+1]){
        a[i]=a[i]*2;
        ans++;
        for(int j=i+1;j<n;j++){
            a[j]=a[j+1];
        }
    }
}
cout<<ans;
}

return 0;
}
