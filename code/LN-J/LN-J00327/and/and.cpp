#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> >a(32,vector<int>(200003,0));
vector<int> sizea(32,0);
int andd(int a,int b){
    long long num=0,bas=1;
    for(int i=0;i<=30;i++){
        if(a%2==1 and b%2==1)num+=bas;
        a/=2;
        b/=2;
        bas*=2;
    }return num;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    m=n-m;
    long long base=1,basee;
    for(int i=1;i<=30;i++)base*=2;
    for(int i=0;i<n;i++){
            basee=base;
        long long g;
        cin>>g;
        for(int j=30;j>=0;j--){
            if(!andd(basee,g)){
                a[j][i]=1;
                sizea[j]++;
            }
            basee/=2;
        }
    }







    long long ans=0;
    for(int i=30;i>=0;i--){
        if(m>=sizea[i]){
            ans+=base;
            m-=sizea[i];
            for(int j=0;j<n;j++){
                if(a[i][j]){
                    for(int i2=30;i2>=0;i2--){
                        if(a[i2][j]){
                            sizea[i2]--;
                            a[i2][j]=0;
                        }
                    }
                }
            }
        }base/=2;
    }cout<<ans;



    return 0;
}
