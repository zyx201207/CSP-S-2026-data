#include<iostream>
#include<algorithm>
using namespace std;
const int N=2147483647;
int n,m,a[200005],ans=-1e9;
void dfs(int andsum,int k,int i){
    if(k==m){
        ans=max(ans,andsum);
        //cout<<andsum<<'\n';
        return;
    }
    if(i>n)return;
    //cout<<"push "<<i<<' ';
    dfs(andsum&a[i],k+1,i+1);
    dfs(andsum,k,i+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(n<=2000&&n>20){
        if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans&=a[i];
            }
        }else if(m==1){
            ans=a[1];
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
    }else{
        dfs(a[1],1,2);
        dfs(N,0,2);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
