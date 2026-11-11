#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int s[10000005];
int b[10000005];
int boo=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int w=1;w<=n;w++){


        int si=n-w+1;

        for(int i=1;i<=n-w+1;i++){
            b[i]=a[i];

        for(int j=1;j<=i;j++){
            if(b[j]==a[i]){

                for(int z=j;z<=i;z++){
                    b[z]=0;
                }
                si=si+j-i;
                b[j]=a[i];
                break;
            }
        }
    }
    for(int v=1;v<=si;v++){
            int x=b[v];
            s[x]++;
    }
    for(int k=2;k<=n-w+1;k++){
            a[k-1]=a[k];
            b[k-1]=0;
    }
}
    for(int i=1;i<m;i++){
        cout<<s[i]<<" ";
    }cout<<n;
    return 0;
}
