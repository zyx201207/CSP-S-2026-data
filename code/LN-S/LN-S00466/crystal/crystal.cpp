#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,k,ans=0,anx=0;
    long long m;
    cin>>n>>m;
    double a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(m==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                anx++;
                i++;
                j++;
            }
        }
        }
        cout<<anx<<endl;
    }
    if(m!=0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i]>>a[j];
                if(a[i]==a[j]){
                    i++;
                    j++;
                }else{
                    k=a[i]-a[j];
                    m=m-k;
                    i++;
                    j++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    cin>>a[i]>>a[j];
            if(a[i]==a[j]){
                ans++;
                i++;
                j++;
            }
        }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
