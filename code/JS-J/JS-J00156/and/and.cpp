#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int cnt=0;
    for(int i=m;i<=n;i++){
        cnt=0;
        for(int j=1;j<i;j++){
            if(a[i]%2==0){
                int y=a[j]/a[i];
                if(y%2==1){
                    cnt++;
                }
            }
            else{
                int y=a[j]/a[i];
                if(y%2==0){
                    if(a[j]==(a[i]*y+(y-1))){
                        cnt++;
                    }
                }
            }
        }
        if(cnt>=m-1){
            cout<<a[i];
            return 0;
        }
    }
    return 0;
}
