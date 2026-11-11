#include<bits/stdc++.h>
using namespace std;
long long a[1000000100];
long long b[1000010];
int main(){
long long n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>b[i];
}
int p=1;
if(m==2){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(j==i)continue;
        a[p]=b[i]&b[j];
        p++;
    }
}
sort(a+1,a+1000000101);
cout<<a[1000000099];
}
if(m==3){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            for(int k=1;k<=n;k++){
                if(j==k||k==i)continue;
                a[p]=b[i]&b[j]&b[k];
                p++;
            }
        }
    }
    sort(a+1,a+1000000101);
    cout<<a[1000000099];
}
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
return 0;
}
