#include<bits/stdc++.h>
using namespace std;
int sum,y;
char a,s[1000000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&x,&a);
        for(int j=1;j<=x;j++){
            y++;
            s[y]=a;
        }
    }
    for(int i=1;i<=y/2;i++)
        if(s[i]!=s[y-i+1])
            sum++;
    printf("%d",sum);
    return 0;
}
