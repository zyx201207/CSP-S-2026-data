#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n,cmpdd;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>cmpdd;
        a[i]=cmpdd;
    }

    if(m==n){
        int re=a[0];
        for(int i=1;i<m;i++){
            re=re&a[i];
        }
        cout<<re;
    }
    else{
        sort(a,a+n);
        int re=a[n-1];
        for (int i=n-2;i>n-m-1;i--){
            re=re&a[i];
        }
        cout<<re;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;

}
