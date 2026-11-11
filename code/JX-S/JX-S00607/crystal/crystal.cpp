# include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int nas=1;
    int *p=&nas;
    int nass=0;
    int num=0;
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=1;j<n;j++){
        num=0;
        nas=0;
        for(int k=2;k<=n;k++){
            num=num+a[n-j]-a[n-k];
            if(num>=m){
                if(nass<nas){
                    nass=nas;
                    continue;
                }
            }
            nas=nas+1;
        }
    }

    cout<<nass<<endl;
    return 0;
}
