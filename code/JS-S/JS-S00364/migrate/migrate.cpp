#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long arr[2000005];
int k;
int minn;
int sum;
void dfs(int i,int j,int l){
    int b=l;
    if(b>minn)return ;
    if(i==j){
        if(b<minn){
            k=1;
            minn=b;
            return ;
        }
        if(b==minn){
            k++;
            return ;
        }
    }
    for(int x=i+1;x<=j;x++){
        if(arr[x]-arr[i]>d)break;
        dfs(x,j,b+1);
    }
    if(b!=0)return ;
    if(k==2)sum++;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        sum=0;
        cin>>n>>d;
        memset(arr,0,n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    k=0;
                minn=INT_MAX;
                if(j-1<=i)continue;
                else dfs(i,j,0);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
//再见c++
