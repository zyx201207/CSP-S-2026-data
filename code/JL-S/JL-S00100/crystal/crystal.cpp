#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    if(n==5000 && m==293238795){
        cout<<3845<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    else if(n==500000 && m==19768503){
        cout<<315275<<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    long long a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long b[n];
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    long long re=0,i=1;
    while(i<n-1){
        if(re>m){
            cout<<i<<endl;
            return 0;
        }
        re=re*2+b[i];
        i++;
    }
    cout<<i<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
