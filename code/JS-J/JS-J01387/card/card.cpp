#include<cstdio>
using namespace std;
int a[100020],b[100010],c[100010]={},d[100010],m,n,t,k;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
scanf("%d""%d",m,n);
for(int x=0;x<m;x++){
scanf("%d",a[x]);
}
for(int z=0;z<m;z++){
        for(int x=0;x<=n;x++){
            c[x]=0;
        }
        for(int x=z;x<m;x++){
            b[x]=0;
        }
        t=0;
    for(int x=z;x<m;x++){

    b[x-t]=a[x];
    if(c[a[x]]>0){
        k=0;
        for(int y=x;y>=0;y+=0){
                if(b[y-t]==a[x]&&k==1){
                    break;
                }
            c[b[y-t]]-=1;
            b[y-t]=0;
            t++;
            k=1;
        }
    }
    c[a[x]]+=1;


}
    for(int y=1;y<=n;y++){
        if(c[y]!=0){
            d[y]++;
        }
    }
}
for(int y=1;y<=n;y++){
        printf("%d"" ",d[y]);
    }
return 0;
}
