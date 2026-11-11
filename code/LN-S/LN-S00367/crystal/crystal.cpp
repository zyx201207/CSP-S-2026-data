#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    vector<int>a;
    int num;
    int ch;
    cin>>num>>ch;
    for(int i=0;i<num;i++){
        cin>>a[i];
    }
    int b=a[0];
    int c;
    sort(a.begin(),a.end());
    for(int m=1;m<num;m++){
        c=a[m];
        a[m]-=b;
        b=c;
    }
    int d=0;
    int ans=0;
    int old=0;
    for(int x=1;x<num;x++){
        for(int y=x;y<num-1&&d<=ch;y++){
            d=a[y+1]*ans+d;
            if(d>ch)continue;
            ans++;
        }
        old=max(old,ans);
        ans=1;
        d=0;
    }
    cout<<old;
    return 0;
}
