#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int a[10001];
char b[10001];
long long int s;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
for(int i=0,j=n-1;i<=j;){
if(a[i]==0)i++;
if(a[j]==0)j--;
long long int t=min(a[i],a[j]);
if(b[i]!=b[j]){
    s+=t;
}
    a[i]-=t;
    a[j]-=t;
}
cout<<s;
return 0;
}
