#include <bits/stdc++.h>
using namespace std;
int main (){
    int n,m,sum=0;
    string s="";
    char a;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&m,&a);
        for(int j=1;j<=m;j++){
            s+=a;
        }
    }
    int r=s.size()-1,l=0;
    while(l<r){
        if(s[r]!=s[l])sum++;
        l++,r--;
    }
    printf("%d",sum);
    return 0;
}
