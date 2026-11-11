#include<bits/stdc++.h>
using namespace std;
long long a[200020],b[200020];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];}
    int q=0;
    if(m==3)
        for(int i=1;i<=n;i++){
           for(int j=1;j<i;j++){
              for(int k=1;k<j;k++){
              q++;
              b[q]=a[i]&a[j]&a[k];
              }
           }
        }
    if(m==2)
        for(int i=1;i<=n;i++){
           for(int j=1;j<i;j++){
              q++;
              b[q]=a[i]&a[j];
           }
        }
    if(m==4)
        for(int i=1;i<=n;i++){
           for(int j=1;j<i;j++){
              for(int k=1;k<j;k++){
                 for(int w=1;w<k;w++){
                    q++;
                    b[q]=a[i]&a[j]&a[k];
                 }

              }
           }
        }
    sort(b+1,b+q+1);
    cout<<b[q];
    return 0;
}
