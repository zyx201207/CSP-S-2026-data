#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000000],b[10000000],l=0,c[3000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n>>m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
            memset(b,0,sizeof(b));
            l=0;
        for(int j = i;j<=n;j++){
                int p=0;
            for(int k = 1;k<=j;k++){
                if(b[k]==a[j]){
                        for(int h = k;h<=n;h++){
                            b[h]=0;
                        }

                    b[k]=a[j];
                    l=k;
                    p=1;
                }


            }
            if(p==0){
                b[++l]=a[j];
            }

        }
        for(int k = 1;k<=n;k++){
            c[b[k]]++;
        }
    }
    for(int i = 1;i<=m;i++){
        cout << c[i]<<" ";
    }
    return 0;
}
