#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],d[1000005],f,s,Min[1000005];
int main(){
    cin>>n>>m;
    b[0]=n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        Min[i]=INT_MAX;
        for(int j = 1;j<=f;j++){
            if(a[i]==d[j]){
                s = 1;
                break;
            }
        }
        if(s==0){
            f++;
            d[f]=a[i];
            s = 0;
        }
    }
    sort(d+1,d+1+n);
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[i]==a[j]){
                b[i]-=i;
                b[j+1]+=i;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        b[i]+=b[i-1];
        for(int j = 1;j<=m;j++){
            if(b[i]==b[j]){
                Min[j]=min(Min[j],b[i]);
            }
        }
    }
    for(int i = 1;i<m;i++){
        cout<<Min[i]<<" ";
    }
    cout<<Min[m]<<endl;
    return 0;
}
