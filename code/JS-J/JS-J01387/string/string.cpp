#include<cstdio>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
string a;
char b;
int m=0,k;
scanf("%d",&k);
for(int x=0;x<k;x++){
    scanf("%d""%c",&m,&k);
    for(int y=0;y<m;y++){
        a+=b;
    }
}
m=0;
if(a.size()%2==0){
for(int x=0;x<a.size()/2-1;x++){
    if(a[x]!=a[a.size()-x-1]){
        m++;
    }
}
}
else{
for(int x=0;x<a.size()/2;x++){
    if(a[x]!=a[a.size()-x-1]){
        m++;
    }
}
}
printf("%d",m);
return 0;
}
