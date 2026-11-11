#include<bits/stdc++.h>
using namespace std;
int n,m;
int num=0;
int a[100001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(m>=(a[i+1]-a[i])*i){
            m-=(a[i+1]-a[i])*i;
            num++;
        }else{
            break;
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
