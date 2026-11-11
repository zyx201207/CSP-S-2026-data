#include<bits/stdc++.h>
using namespace std;
int n,m;
double a[1000000];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    int  l=1,r=n/2+1;
    int cnt=0;
    for(int i=r;i>=1;i++){
        if(m!=0){
        a[i]=a[r];
        m-=a[r]-a[i];
        }else{
            int z=a[r];
            for(i=1;i<=n;i++){
                if(a[i]==z){
                    cnt++;
                }
            }
            cout<<cnt;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
