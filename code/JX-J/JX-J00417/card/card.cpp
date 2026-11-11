#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],now[N],js[M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int cnt=1;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(cnt<=n){//di ji lun
        for(int i=1;i<=n;i++) now[i]=0;
        int num=0;
        for(int i=cnt;i<=n;i++){//fang di ji zhang
            int flag=0;
            for(int j=1;j<=num;j++){//check whether same
                if(now[j]==a[i]){//same
                    flag=1;
                    int kkk=num;
                    for(int k=j;k<=kkk;k++){//shan chu
                        now[k]=0;
                        num--;
                    }
                    num++;
                    now[num]=a[i];
                }
            }
            if(flag==0){
                num++;
                now[num]=a[i];
            }
            /*for(int j=1;j<=num;j++) cout<<now[j]<<" ";
            cout<<"\n";*/
        }
        for(int i=1;i<=m;i++){
            int flag=0;
            for(int j=1;j<=n;j++){
                if(now[j]==i) flag=1;
            }
            if(flag==1) js[i]++;
        }
        cnt++;
    }
    for(int i=1;i<=m;i++) cout<<js[i]<<" ";
    return 0;
}
