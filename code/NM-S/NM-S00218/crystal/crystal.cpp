#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
long long zheng[500005];
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int point=1;
    long long mx=-1;
    while(point<=n-1){
        long long mm=m;
        int z=0;
        for(int i=0;i<n;i++){
            cha[i]=a[point]-a[i];
            if(cha[i]>=0){
                zheng[z]=cha[i];
                z++;
            }

        }
        sort(zheng,zheng+z,cmp);
        int cnt=0;
        int i=0;
        while(z--){
            if(mm>=zheng[i]){
                mm-=zheng[i];
                cnt++;
                i++;
            }else{
                break;

            }
        }
        if(cnt>mx) mx=cnt;
        point++;
    }
    cout<<mx;
    return 0;
}
