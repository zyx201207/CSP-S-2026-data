#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){//1

        for(int l=1;l<=n;l++){//2.1
            b[l] = 0;
        }
        for(int j = i;j<=n;j++){//2.2
            b[a[j]+=1;
            if(b[a[j]>1){
                for(int k = 1;k<j;k++){//3
                    b[a[k]] = 0;
                }
            }
        }
        for(int s = 1;s<=n;s++){//2.3
            c[s]+=b[s];
        }

    }
    for(int i=1;i<=m;i++){
        cout<<c[i];
    }
    flose(stdin);
    fclose(stdout);
    return 0;
}
