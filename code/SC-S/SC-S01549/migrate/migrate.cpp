#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int c,t;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>c>>t;
while(t--){
        int n,d,x=0;
cin>>n>>d;
int a[N];
for(int i=0;i<N;i++)
    a[i]=0;
for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-2;i++)
if(a[i+2]-a[i]<=d)x++;
cout<<x<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
