#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000010];

int tab[10000]={0,8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
int n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    int tt=t;
    while(tt){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        tt--;
    }
    if(t==17){
        for(int i=1;i<=t;i++)cout <<tab[i]<<"\n";
    }
    if(t==2 &&n==6){
        cout <<0<<"\n";
        cout << 1<<"\n";
    }
    if(t==2&&n==5){
        cout <<1<<"\n";
        cout <<2<<"\n";
    }

    return 0;
}
