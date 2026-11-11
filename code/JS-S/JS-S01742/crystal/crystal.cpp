#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int dj=0,cz=0;
    while(dj<=m){
        int l=1;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                l++;
                cz++;
            }else break;
        }
        dj+=l*(a[cz+1]-a[cz]);
        cz++;
    }
    cout<<cz<<n;
    fclose(stdin);
    fclose(stdout);
}
