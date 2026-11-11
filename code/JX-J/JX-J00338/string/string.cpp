#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n],f=0,y=0,r=0;
    char b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        f=f+a[i];
    }
    char c[f];
    for(int i=0;i<f;i++){
        for(int j=0;j<n;j++){
            y=y+a[j];
            if(i<y)
                c[i]=b[j];
        }
    }
    int m=0;
    if(f%2==0){
        m=f/2;
        char p[m],q[m];
        for(int i=0;i<m;i++){
            p[i]=c[i];
        }
        for(int i=f-1;i>m-1;i--){
            q[i]=c[i];
        }
        for(int i=0;i<m;i++){
            if(p[i]!=q[i])
                r++;
        }
    }
    else {
        m=(f-1)/2;
        char p[m],q[m];
        for(int i=0;i<m;i++){
            p[i]=c[i];
        }
        for(int i=f-1;i>m;i--){
            q[i]=[i];
        }
        for(int i=0;i<m;i++){
            if(p[i]!=q[i])
                r++;
        }
    }
    cout<<r;
    return 0;
}
