#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n;
bool f1(int b){
    for(int i=1;i<=n;i++){
        if(a[i]==b){
            return 1;
        }
    }
    return 0;
}
int b[2000005]={0};
int c1=2000000;
int nt=1;
int bs=1;
void f(int a1,int b1,int c){
    if(a1==b1){
        if(c1==b[b1]){
            nt++;
        }
        else{
            if(b[b1]<c1){
                nt=1;
                c1=b[b1];
            }
        }
        return;
    }
    for(int i=c;i>=1;i--){
        if(f1(a[a1]+i)){
            b[a[a1]+i]=bs++;
            f(a[a1]+i,b1,c);
            bs--;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","s",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while(t--){
        int d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                nt=1;
                c1=2000000;
                bs=1;
                f(k,i,d);
                if(nt==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
}
