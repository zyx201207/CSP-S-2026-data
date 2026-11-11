#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,m=0,r=0;
cin>>n;
for(long long i=0;i<n;i++){
    cin>>a[i]>>c[i];
    m+=a[i];
    if(c[i]==c[i+1]){r=r;}
}
for(long long i=0;i<m/2;i++){
    if(c[i]!=c[m-i]){
        r++;
    }
}
cout<<r;
fclose(stdin);
fclose(stdout);
return 0;
}
