#include<bits/stdc++.h>
using namespace std;
long long n,m,c,ma=INT_MIN;
long long a[100005],b[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ma<(a[i]&a[j])){
                    ma=(a[i]&a[j]);
                }
            }
        }
        cout<<ma;
    }
    else{
        cout<<a[n-1];
    }
    fclose(stdin);
    fclose(stdout);
}
