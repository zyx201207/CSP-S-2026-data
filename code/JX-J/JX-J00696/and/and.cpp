#include<bits/stdc++.h>
using namespace std;
bool s[200001][30];
int q[30]={1073741824,536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,1048576,524288,462144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2};
void f(int x,int y){
    for(int i=0;i<30;i++){
        if(x>q[i]){
            x-=q[i];
            s[y][i]=1;
        }
    }
}
struct p{
    int g,h;
};
bool f1(p x,p y){
    return x.g<y.g;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        f(a[i],i);
    }
    int sum,e[m];
    p w[n];
    for(int i=0;i<30;i++){
        sum=0;
        for(int j=0;j<n;j++){
            if(s[j][i]){
                w[sum].g=a[j];
                w[sum].h=j;
                sum++;
            }
        }
        if(sum>=m){
            sort(w,w+sum,f1);
            for(int j=0;j<m;j++){
                e[j]=w[sum-j-1].g;
            }
            for(int j=i;j<=30;j++){
                bool x=1;
                for(int k=0;k<m;k++){
                    if(s[w[k].h][j]==0){
                        x=0;
                        break;
                    }
                }
                if(x){
                    ans+=q[j];
                }
            }
            break;
        }
    }
    cout<<ans;
    return 0;
}
