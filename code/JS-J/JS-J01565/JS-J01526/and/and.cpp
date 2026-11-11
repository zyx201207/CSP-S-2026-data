#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int k=0;
    int a[31][20005];
    for (int i=0;i<n;i++){
        cin >> a[0][i];
    }
    for (int i=30;i>=0;i++){
        int cnt=0,cnt2=0;
        for (int j=0;j<n;i++){
            int r=(a[k][j]>>i)%2;
            if (r){
                a[k+1][cnt++]=j;

            }
            else{
                ;

            }
            if (cnt==m){
                int ans=a[k+1][0];
                for (int j=1;j<cnt;j++)
                    ans&=a[k+1][j];
                cout << ans;
                return 0;
            }
            else if (cnt>m){
                k++;
                n=cnt;
            }
        }

    }
    return 0;
}


