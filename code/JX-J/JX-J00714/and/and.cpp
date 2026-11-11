#include <iostream>
#include <algorithm>
using namespace std;
const int k=2e4;
int l[k+1][9];
void zhuan(int a,int w){
    int p=8;
    while(a!=0){
        int t=1;
        for(int i=1;i<=p;i++){
            t*=2;
        }
        if(a>=t){
            l[w][p]=1;
            a-=t;
        }
        else{
            if(a==1){
                l[w][0]=1;
                return ;
            }
            p--;
        }
    }
    return;
}
int pai(int x,int y){
    int t=0,t1=1;
    for(int i=0;i<=9;i++){
        if(i>=1){
            t1*=2;
        }
        if(l[x][i]==1&&l[y][i]==1){
            t+=t1;
        }
    }
    return t;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        zhuan(a[i],i);
    }
    int max1;
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                max1=max(pai(i,j),max1);
                cout<<pai(i,j)<<endl;
            }
        }
    }
    cout<<max1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

