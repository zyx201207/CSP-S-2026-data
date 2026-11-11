#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,len=0;
    cin>>m>>n;
    int a[m];
    for(int i=0;i<m;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        int teama[m],x=0,teamb[n];
        for(int j=len;j<m;j++){
            teama[x]=a[j];
            x++;
        }
        for(int j=0;j<m-len;j++){
            for(int s=j+1;s<m-len;s++){
                if(teama[j]==teama[s]){
                    for(int d=j;d<s;d++) teama[d]=0;
                }
            }
        }
        for(int j=0;j<m-len;j++){
            b[teama[j]]++;
        }
        len++;
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
