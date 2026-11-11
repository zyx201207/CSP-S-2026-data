#include<bits/c++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
int a[100005][100005];
int l[100005][100005];
int tnt=0;
int main(){
    freopen("migrate.max","r",in);
    freopen("migrate.max","w",out);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
    
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i<=d){
                    a[i][j]=1;
            }
        }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i][j]==1){
                continue();
            }else{
                for(int k=i+1;k<=j;k++){
                    if(a[i][k]==1&&a[k][j]==1){
                        sum++;
                }
        }
        if(sum==2){
            tnt++;
        }
        
        
    }
    }
    }
    cout<<tnt<<endl;
    }
    fclose(in);
    fclose(out);
    return(0);

}
