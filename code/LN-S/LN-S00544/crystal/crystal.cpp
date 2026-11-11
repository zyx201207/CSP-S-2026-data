#include <bits/stdc++.h>
using namespace std;
int a[500005];
int dc[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    //dc[0]=a[1]-a[0];
    for(int i=1;i<n;i++){
        dc[i]=a[i]-a[i-1];
        //if(dc[i]<0)dc[i]=-1*dc[i];
    }
/*
    for(int i=0;i<n;i++){
        cout<<dc[i];
    }cout<<endl;
*/

    int cnt=0;
    for(int l=0;l<n;l++){
        int r=l+1;
        long long tmp=m;
        while(r<n){
            int tmp2=r;
            r++;
            if(tmp < dc[r-1]){r--;break;}
            for(int k=0;k<tmp2;k++){
                if(tmp>=dc[r-1])tmp-=dc[r-1];
                else {r--;break;}
            }
        }
        cnt=max(cnt,r-l);
    }
    cout<<cnt;
    return 0;
}
