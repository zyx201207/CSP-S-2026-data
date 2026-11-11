#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
char c[N];
int a[N];
int app(int n,long long s){
    long long l=1,r=s-1,x=a[1],y=s-a[n],k=0;
    int i=1,j=n;
    while (l<r){
        int g=min(a[i],a[j]);
        l+=g;
        r-=g;
        if(c[i]!=c[j]){
            k=k+g;
        }
        if(l>x){
            x+=a[++i];
        }
        if(r<y){
            y-=a[--j];
        }
    }
    return k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    long long s=0;
    for(int i=1;i<=n;i++){
        scanf("%d%s",&a[i],&c[i]);
        s=s+a[i];
    }
//    cout<<s<<endl;
    cout<<app(n,s);
   // fclose(stdin);
   // fclose(stdout);
    return 0;
}
