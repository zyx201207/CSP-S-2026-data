#include<bits/stdc++.h>
using namespace std;
int a[1000000],mn[1000000],t[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=true;
            int x=0;
            for(int k=1;k<=n;k++){
                if(mn[k]==a[j]){
                    flag=false;
                    x=k;
                    break;
                }
            }
            if(flag){
                mn[j]=a[j];
            }
            else{
                for(int k=x;k<=n;k++){
                    mn[k]=0;
                }
                mn[j]=a[j];
            }
        }
        for(int j=i;j<=n;j++){
            t[mn[j]]+=1;
            mn[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout << t[i] << " ";
    }
    return 0;
}
