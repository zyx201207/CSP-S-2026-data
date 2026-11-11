#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        scanf("%d %c",&a,&c);
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int l=s.size();
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
         if(s[i]!=s[l-i-1]){
            cnt++;
         }
    }
    cout<<cnt;
    return 0;
}
