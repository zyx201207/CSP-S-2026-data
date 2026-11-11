#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[900010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int l=0,c=0;
            for(int q=1;q<=n;q++){
                if(a[q]==j){
                    l=1;
                    c=q;
                    break;
                }
            }
            if(l==0){
                a[++n]=j;
            }else{
                for(int p=c+1;p<=n;p++){
                    n--;
                    a[p]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
