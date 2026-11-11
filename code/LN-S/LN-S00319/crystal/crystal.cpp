#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,maxn=0,num;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    for(int i=1;i<n;i++){
        num=1;
        int mx=m;
        for(int j=i-1;j>=0;j--){
            if(x[i]-x[j]<=mx){
                num++;
                mx-=x[i]-x[j];
            }
            else{
                break;
            }
        }
        maxn=max(maxn,num);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
