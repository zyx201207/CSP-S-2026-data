#include<bits/c++.h>
using namespace std;
int c,n,m,d,q;
int w[50005],t[50005][50005];
int main(){
    freopen("subway.max","r",in);
    freopen("subway.max","w",out);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k;
    int a;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a;
            cin>>t[i][a];
            
        }
    }
    int x,y;
    int sum=0;
    for(int i=1;i<=r;i++){
        cin>>x>>y;
        int tnt=0;
        for(int j=1;j<=n;j++){
            if(t[i][x]!=0&&t[i][y]!=0){
                tnt=tnt+w[x]+w[y];
                for(int k=x;k<=y;k++){
                if(t[i][a]!=0){
                      tnt=tnt+t[i][a];
                }
                }
                sum=min(sum,tnt);
        }
        
    }
    
    cout<<sum;
    fclose(in);
    fclose(out);
    return(0);//今天是万圣节不给分就捣蛋

}
