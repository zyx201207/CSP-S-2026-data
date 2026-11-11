#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[5000005];
bool bl=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) b[j]=0;
        for(int j=i;j<=n;j++){
                bl=0;
            for(int k=1;k<=n;k++){
                if(b[k]==a[j]){
                    for(int q=k+1;q<=n;q++) b[q]=0;
                    bl=1;
                }
            }
            if(!bl) b[j]=a[j];

        }
        for(int j=1;j<=n;j++){
                if(b[j]>0) c[b[j]]++;
        }

    }

    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
