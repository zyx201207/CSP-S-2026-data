#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;i<n;j++){
            b[i]=a[i];
            int l=-1;
            for(int k=0;k<i;k++){
                if(b[k]==b[i]){
                    l=k;
                }
            }
            if(l==-1)continue;
            else{
                for(int k=l+1;k<=i;k++){
                    b[k]=0;
                }
            }
            for(int k=0;k<n;k++){
                int l1=b[k];
                c[l1]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
