#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int e[500005];
long long m;
int n;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n>=10000){
        cout<<n;
    }
    else{
    sort(a,a+n);
    int d=0;
    if(m==0){
        for(int i=0;i<n;i++){
            if(d==a[i]){
                e[d]++;
            }
            else{
                d=a[i];
                e[d]++;
            }
        }
        sort(e,e+n,cmp);
        cout<<e[m];
    }
    int p=0;
    int y=n;
    while(m>0&&y>0){
            int w=m;
            int sum=0;
        for(int i=0;i<n;i++){
            if(a[y]>a[i]&&w>0){
                w-=a[y]-a[i];
                b[i]=a[y];
                if(w<0){
                    b[i]=a[i];
                }
            }
            else{
                b[i]=a[i];
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]==a[y]){
                sum++;
            }
        }
        c[p++]=sum;
        y--;
    }
    sort(c,c+p,cmp);
    cout<<c[0];
    }
return 0;
}
