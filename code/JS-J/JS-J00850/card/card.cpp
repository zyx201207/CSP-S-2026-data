#include <iostream>
#include <cstring>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,j=0;
    cin>>n>>m;
    int h[n],a[m]={0};
    int js[n]={0};
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int mask=0;mask<n;mask++){
        memset(js,0,sizeof(js));
        j=0;
        for(int i=mask;i<n;i++){
            for(int k=0;k<j;k++){
                if(js[k]==h[i]){
                    int l=j;
                    for(int m=k;m<l;m++){
                        js[m]=0;
                        j--;
                    }
                    break;
                }
            }
            js[j]=h[i];
            j++;
        }
        for(int k=0;k<j;k++){
            a[js[k]-1]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
