#include<bits/stdc++.h>
using namespace std;
int a,d,c[100005],ans;
void recur(int times,int mid){
    if(times>d+1){
        ans=max(mid,ans);
        return;
    }
    for(int i=times+1;i<=a;i++){
        recur(times+1,mid&c[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>d;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    recur(1,pow(2,31)-1);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
