#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool num[200010][40],ans[40],f[200010];
void turn(int n,int x){
    int cnt=35;
    while(x>0){
        num[n][--cnt]=x%2;
        x/=2;
    }
}
void turn2(){
    int an=0;
    for(int i=1;i<=34;i++){
        an=an*2+ans[i];
    }cout<<an;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(f,1,200001);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        turn(i,a[i]);
    }int anscnt=0;
    for(int j=1;j<=34;j++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(f[i]){
                cnt+=num[i][j];
            }
        }
        if(cnt>=m){
            ans[j]=1;
            for(int i=1;i<=n;i++){
                if(num[i][j]!=1){
                    f[i]=0;
                }
            }
        }
    }
    turn2();
    return 0;
}
