#include<bits/stdc++.h>
using namespace std;
long long z,x,s,e;
string q,a;
char w;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&z);
    for(int i=1;i<=z;i++){
        scanf("%lld %c",&s,&w);
        for(int j=1;j<=s;j++){
            q=q+w;
        }
    }
    x=q.size();
    for(int i=0;i<x/2;i++){
        if(q[i]!=q[x-1-i]) e++;
    }
    printf("%lld",e);
    fclose(stdin);
    fclose(stdout);
}
