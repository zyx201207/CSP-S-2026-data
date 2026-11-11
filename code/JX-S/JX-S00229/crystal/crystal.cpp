#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[5000000];
int b[5000000];
int c[5000000];
int d[5000000];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(a[j]<a[i]){
                int tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
        }
    }
    int q=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[j]=a[i]-a[j];
            if(b[j]<0){
                b[j]=-1;
            }
        }
        int _n=n;
        for(int j=0;j<n;j++){
            if(b[j]<0&&_n==n){
                _n=j;
            }
        }
        int num=0;
        int cnt=0;
        for(int L=0;L<n;L++){
            for(int R=L+1;R<_n;R++){
                for(int j=L;j<=R;j++){
                    num+=b[j];
                    cnt++;
                }
            }
        }
        c[q]=cnt;
        q++;
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(c[i]==a[j]){
                d[i]=c[i];
            }
        }
    }
    for(int i=0;i<q;i++){
        for(int j=i;j<n;j++){
            if(d[j]<d[i]){
                int tmp=d[j];
                d[j]=d[i];
                d[i]=tmp;
            }
        }
    }
    cout<<d[n-1]<<endl;
    return 0;
}
