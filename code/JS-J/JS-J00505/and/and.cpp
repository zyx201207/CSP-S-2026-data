#include<bits/stdc++.h>
using namespace std;
int ma=INT_MIN,n,m,a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma;
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
