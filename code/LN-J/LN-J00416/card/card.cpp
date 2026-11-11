#include<iostream>
#define N 500005
#define M 300005
using namespace std;
int count[M];
int num[N];
int check[N];
bool app[M];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int p=1;
    for(int i=1;i<=n;i++){
        p=1;
        for(int j=i;j<=n;j++){
            if(!app[num[j]]){
                check[p++]=num[j];
                app[num[j]]=true;
            }else{
                while(check[p]!=num[j]){
                    check[p]=false;
                    p--;
                }
            }
        }
        for(int j=1;j<=p;j++){
            count[check[i]]+=app[check[i]];
        }
        for(int i=1;i<=m;i++){
            app[i]=false;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<count[i]<<' ';
    }
}
