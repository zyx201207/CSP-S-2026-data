#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool k[200010][31];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int z=a[i];
        int c=0;
        while(z){
            if(z%2==1){
                k[i][c]=1;
            }
            z/=2;
            c++;
        }
    }
    long long sum=0,s=30,q=0;
    while(q<m){
        for(int i=1;i<=n;i++){
            if(k[i][s] && q==0){
                sum=a[i];
                q++;
            }
            else{
                if(k[i][s]){
                    sum=sum&a[i];
                    q++;
                }
            }
            if(q==m)break;
        }
        s--;
    }
    cout<<sum;
    return 0;
}
