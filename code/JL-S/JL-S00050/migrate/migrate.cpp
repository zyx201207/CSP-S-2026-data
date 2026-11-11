#include<bits/stdc++.h>
using namespace std;
const int N 2e6+10;
long long ans;
int a[N],b[N],c[N],d[N],q[N];
map<int ,int>p;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stout);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p[a[i]=i;
        b[i]=a[i]+d;
    }
    int k=0;
    for(int l=0;i<n;i++){
        while(b[k]>=a[i]&&b[k]<=a[i+1]){
            if(!c[i]) c[i]=k;,e[i+1]=k,p[k] =i;
                k++;

        }

    }
    for(int i=0;i<n;i++){
        if(c[i]){
            if(p[a[i]]==c[i]+1) p[i]=c[i];
        }
        if(c[i-1]){
            ans+=(c[i]-c[i])*(p[i]-q[i]);

        }
        if(c[i-1]){
            ans+=(e[i]-c[i])*(p[i]-q[i]-d[p[i]]);
        }


    }
    cout<<-1*ans<<'\n;

}
