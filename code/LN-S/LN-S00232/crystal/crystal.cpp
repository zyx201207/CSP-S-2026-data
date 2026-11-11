#include<bits/stdc++.h>
using namespace std;
long long a1[100000000],maxx=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    cin>>a[0];
    for(long long i=1;i<n;i++){
        cin>>a[i];
    }
    int maxxx=0,mi=m;
    for(int j=0;j<n;j++){
        for(int i=j;i<=n;i++){
            if(abs(a[i]-a[j])<=mi){
                mi-=abs(a[i]-a[j]);
                maxxx+=1;
            }
        }
        maxx=max(maxx,maxxx);
        maxxx=0;
        mi=m;
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
