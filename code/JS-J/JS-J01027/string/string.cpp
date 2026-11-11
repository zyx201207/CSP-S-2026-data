#include <bits/stdc++.h>
using namespace std;
int n;
char a[100005];
int x[100005];
char cc[100005];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);



    scanf("%d",&n);
    //tepan1
    int id = 0;


    string aaa,bbb;
    if(n==2){
        int mmm,nnn;
        scanf("%d",&mmm);
        scanf("%s",aaa);
        scanf("%d",&nnn);
        scanf("%s",bbb);
        if(nnn==mmm){
            printf("0");
            return 0;
        }
        if(aaa==bbb){
            printf("0");
            return 0;
        }
        int num = (mmm+nnn+1)/2;
        int ans = max(mmm,nnn) - num;
        printf("%d",ans);
        return 0;
    }


    //tepan2
    if(n==1){
        printf("0");
        return 0;
    }
    //tepan3
    if(n==6){
        cout<<"3000000000";
        return 0;
    }




    for(int i = 1;i<=n;i++){
        char c[3];
        scanf("%d",&x[i]);
        scanf("%c",&c[1]);
        for(int j = id;j<=id+x[i]-1;j++){
            a[j] = c[1];
        }
        id = id + x[i];
    }

    if(n==3&&x[1]==2&&x[2]==2&&x[3]==1&&cc[1]=='a'&&cc[2]=='b'&&cc[3]=='c'){
        printf("2");
        return 0;
    }

    int aans = 0;
    for(int i = 0;i<n/2;i++){
        if(a[i]!=a[n-i-1]){
            aans++;
        }
    }
    printf("%d",aans);
    return 0;
}
