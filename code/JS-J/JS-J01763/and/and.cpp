#include <bits/stdc++.h>
using namespace std;
long long a[200000+5];
int b[200000+5];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int max1=0;

    for(int j=1;j<=n;j++){
        for(int k=j+1;k<=n;k++){
            if(a[j]&a[k]>max1){
                max1=a[j]&a[k];
                b[j]=1;
                b[k]=1;

            }
        }
    }
    for(int i=1;i<=m-2;i++){
        int max2=0;
        for(int j=1;j<=n;j++){
           if(a[j]&max1>max2&&b[j]!=1){
                max2=a[j]&max1;
                b[j]=1;
            }

        }
        max1=max2;
    }

cout << max1;
return 0;
}

