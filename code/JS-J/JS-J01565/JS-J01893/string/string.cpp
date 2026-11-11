#include<bits/stdc++.h>
using namespace std;

int n,ans = 0;
string s = "";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      int a;
      char c;
      cin>>a>>c;
      for(int i=1;i<=a;i++){
        s+=c;
      }
    }
    int m = s.length();
    for(int i=0;i<m/2;i++){
      if(s[i]!=s[m-i-1]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
