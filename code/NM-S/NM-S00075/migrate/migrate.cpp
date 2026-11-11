#include<bits/stdc++.h>
using namespace std;

long long c,t,n,a[2000009],b[2000009];
unsigned long long d;
int le(long long fr,long long tou,long long comp){
    while (fr<tou){
        long long mid=(fr+tou)/2;
        if (b[mid]>comp){
            tou=mid;
        }
        else{
            fr=mid+1;
        }
    }
    return tou;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        b[1]=1;
        long long k=1,ans=0;
        for (int i=1;i<n;i++){
            for (int j=i+1;j<=n;j++){
                if (a[j]-a[i]<=d){
                    b[++k]=a[j];
                }
                else {
                    break;
                }
            }
        }

        sort(b+1,b+k+1);
        b[++k]=100000000;
        for (int i=1;i<=n-2;i++){
            for (int j=i+2;j<=n;j++){
                long long left,right;
                left=le(1,k,a[i])-1;
                right=le(1,k,a[j])-1;
                if ((right-left)==(j-i+1)){
                    ans++;
                }
            }
        }


        cout<<ans<<endl;

    }

    return 0;
}
