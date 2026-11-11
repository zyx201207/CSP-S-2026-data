#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    while(m>0){
        int mi=a[0],i0;
        for(int i=0;i<n;i++){
            if(mi!=a[i]){
                i0=i;
                break;
            }
        }
        m-=(a[i0]-mi);
        a[0]=a[i0];
        sort(a,a+n);
    }
    int num=0;
    for(int i=1;i<n;i++){
        if(a[0]==a[i]){
            num++;
        }
    }
    cout<<num+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
