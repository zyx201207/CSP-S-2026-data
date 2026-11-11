#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,num=0;
    int s[100005]={0};
    int hh;
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;1<n;i++){
        for(int j=i+1;j<=n;j++){
            num=0;
            for(int p=1;p<=j;p++){
                if(j-p<i){
                    break;
                }
                num=num+(a[j]-a[j-p]);
                if(num==m){
                    s[i]=j-i+1;
                    i++;
                    j=n;
                }
                if(num>m){
                    s[i]=j-i;
                    i++;
                    j=n;
                }
            }
        }
        if(i==n-1&&num<m){
            cout<<n;
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        if(s[i]<s[i-1]&&hh<s[i-1]){
            hh=s[i-1];
        }else if(hh<s[i]){
            hh=s[i];
        }
    }
    cout<<hh;
    return 0;
}
