#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000202],mm[2000202];
int desk[2000202],top=0;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int ci=1;ci<=n;ci++){
        top=0;
        memset(desk,0,sizeof(desk));
        for(int i=ci;i<=n;i++){
            bool okk=0;
            int nm=0;
            for(int j=1;j<=top;j++){
                if(desk[j]==a[i]){
                    okk=1;
                    nm=j;
                    break;
                }
            }
            if(!okk){
                desk[++top]=a[i];
            }else{
                for(int j=nm;j<=top;j++){
                    desk[j]=0;
                }
                top=top-(top-nm+1);
                desk[++top]=a[i];
            }
        }
        for(int i=1;i<=top;i++){
            mm[desk[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mm[i]<<" ";
    }
    return 0;
}
