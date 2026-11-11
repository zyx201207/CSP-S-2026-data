#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int b[100001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }else if(m==n-1){
        int x[3]={1,1,1};
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                x[i]&=a[j];
            }
        }
        cout<<max(x[1],x[0]);
    }
    else{
        for(int i=0;i<n-m;i++){
            int s=a[i];
            for(int j=i+1;j<m+i;j++){
                s&=a[j];
            }
            b[i]=s;
        }
    sort(b,b+n-m);
    cout<<b[n-m-1];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
