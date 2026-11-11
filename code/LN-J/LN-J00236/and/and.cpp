#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[20005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int d=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                int t=a[i]&a[j];
                d=max(d,t);
            }
        }
        cout<<d;
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=2;j<i;j++){
                for(int p=1;p<j;p++){
                    int t=a[i]&a[j]&a[p];
                    d=max(d,t);
                }
            }
        }
        cout<<d;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
