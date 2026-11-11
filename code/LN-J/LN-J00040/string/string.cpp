#include <bits/stdc++.h>
using namespace std;
int a[200000];
string s;
char c[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
    sum+=a[i];
    for(int j=a[i-1]+1;j<=a[i];j++){
        s[j]=c[i];
        }
    }
    for(int i=1;i<=sum/2;i++){
        if(s[sum]!=s[i]){
            num++;
            sum--;
        }
    }
    cout<<num;


return 0;
}
