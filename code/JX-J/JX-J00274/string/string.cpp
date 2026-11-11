#include<bits/stdc++.h>
using namespace std;

const int N=100005;
long long a[N],ans,n;
char c[N];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i]>>c[i];
}
int i=1,j=n;
while(i<j){
    if(c[i]!=c[j]){
        ans+=min(a[i],a[j]);
    }
    if(a[i]>a[j]){
        a[i]-=a[j];
        --j;
    }
    else if(a[i]<a[j]){
        a[j]-=a[i];
        ++i;
    }
    else{
        ++i;
        --j;
    }
}
cout<<ans;
return 0;
}
