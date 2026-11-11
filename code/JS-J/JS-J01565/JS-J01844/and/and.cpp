#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int rm[200005];
int f[32]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n,cmp);
    int mc=0;
    int mx=a[0];
    while(mx>0){
        mx>>=1;
        mc++;
    }
    int c=0;
    while(c<m&&mc>0){
        mc--;
        c=0;
        for(int i=0;i<n;i++){
            if(a[i]>=f[mc]){
                c++;
            }
        }
    }
    mc++;
    for(int i=c;i<n;i++){
        a[i]=-1;
    }
    memset(rm,-1,sizeof(-1));
    if(c==m){
        f[mc]--;
        cout<<f[mc]<<' ';
        for(int i=0;i<c;i++) cout<<a[i]<<' ';
        cout<<f[mc];
    }
    else{
        while(1){
            for(int i=0;i<n;i++){
                b[i]-=f[mc-1];
            }
            int js=0,pos=0;
            while(js<m){
                mc--;
                if(mc==0){
                    f[mc]--;
                    for(int i=0;i<n;i++){
                        if(a[i]==-1) break;
                        f[mc]=f[mc]&a[i];

                    }
                    cout<<f[mc];
                    return 0;
                }
                memset(rm,-1,sizeof(rm));
                js=0;
                for(int i=0;i<n;i++){
                    if(b[i]>=f[mc]){
                        js++;
                        rm[pos]=i;
                        pos++;
                    }
                    else break;
                }
            }
            int p=0;
            for(int i=0;i<n;i++){
                if(rm[p]!=i) a[i]=-1;
                else p++;
            }
        }
    }
    return 0;
}
