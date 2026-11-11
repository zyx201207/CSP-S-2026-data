#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
    freopen("card.in","l",stdin);
    freopen("card.out","r",stdout);
    int n,m;
    int k=0,l=0,h=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            b[j]=a[j];
            for(int g=0;g<=j;g++){
                if(b[g] == b[j]){
                    b[g] = 0;
                }
            }
        }
        for(int j=0;j<=n-i;j++){
            if(b[j]==1){
                k+=1;
            }
            if(b[j]==2){
                h+=1;
            }
            if(b[j]==3){
                l+=1;
            }
        }
    }
    cout << k <<" " << h << " " << l ;
    return 0;
}
