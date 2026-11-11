#include <bits/stdc++.h>
using namespace std;
int n,num,a[100000005],ans;
int u=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    int q;
    char s;
    cin>>q>>s;
    num+=q;
    for(int j=1;j<=q;j++){
        a[++u]=s-'a';

    }
}
if(num==1){
    cout<<0;return 0;
}else if(num%2==1){
for(int i=1;i<num/2+1;i++){
    if(a[i]!=a[num+1-i])ans++;
}
}else{
 for(int i=1;i<=num/2;i++){
     if(a[i]!=a[num+1-i])ans++;
 }
}
cout<<ans;
return 0;
}
