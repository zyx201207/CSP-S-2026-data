#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
freopen("and.in","r"stdin);
freopen("and.out","w"stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int m;
cin>>m;
for(int i=1;i<=m;i++){
    cin>>a[i];
}
long long Max=0;
for(int i=1;i<=m;i++){
    if(m*a[i]+m>Max){
        Max=m*a[i];
    }
}
cout<<Max;
return 0;
}

