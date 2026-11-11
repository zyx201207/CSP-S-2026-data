#include<bits/stdc++.h>
using namespace std;
long long n,ans,k;
char c[100000005];
int main(){
//    clock_t st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            int x;
         char s;
        cin>>x>>s;
        for(int j=1;j<=x;j++)c[++k]=s;
    }
    for(int i=1;i<=k/2;i++){
        if(c[i]!=c[k-i+1])ans++;
    }
  //  clock_t et=clock();
 //   double s=double(et-st)/CLOCKS_PER_SEC;
 //   double ms=s*1000;
    cout<<ans;
 //   cerr<<ms;
return 0;
}
