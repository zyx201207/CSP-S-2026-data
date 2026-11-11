#include<bits/stdc++.h>
int main(){
    using namespace std;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int an[t];
    for(int i=0;i<t;i++){
        long n,d,cn=0;
        cin>>n>>d;
        long x[n];
        for(long &j:x){
            cin>>j;
        }
        int a[n][n];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                a[j][k]=-1;
            }
        }
        for(int j=0;j<n;j++){
            a[j][j]=0;
            for(int k=j+1;k<n;k++){
                long mi=-1;
                int l=k-1;
                while(l>=j){
                    if(a[j][l]!=-1 &&( x[k]-x[l]<=d)){
                        if(a[j][l]+1<mi||mi==-1){
                            mi=a[j][l]+1;
                        }
                        l--;
                    }
                    else{
                        break;
                    }
                }
                a[j][k]=mi;
            }
        }
        for(int j=2;j<n;j++){
            for(int k=0;k<j;k++){
                int bn=0;
                for(int l=k+1;l<j;l++){
                    if(a[k][l]+a[l][j]==a[k][j]){
                        bn++;
                        if(bn>2){
                            break;
                        }
                    }
                }
                if(bn==2){
                    cn++;
                }
            }
        }
        an[i]=cn;
    }
    for(auto i:an){
        cout<<i<<endl;
    }
}
