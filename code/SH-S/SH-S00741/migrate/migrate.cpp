#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int arr[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,e;
    cin>>c;
    cin>>t;
    for(int i=1;i<=t;i++){
        int sz,d;
        cin>>sz>>d;
        int sum=0;
        int x;
        for(int i=1;i<=sz;i++){
            cin>>x;
            arr[i]=x;
            sum+=x;
        }
        int alf=arr[sz+1]-arr[1];
        int cnt=alf/d;
        int nct=alf%d;
        int res=cnt*nct+1;
        if((sum==0)&&(cnt==1)&&(nct==1)) res=0;
        ans+=res;
        cout<<res<<'\n';
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
