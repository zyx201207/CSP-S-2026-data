#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; long long m; cin>>n>>m;
    int a[1e18];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }                                   
    int temp=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            if(a[j]<a[j-1]) {
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
                j--;
            }
        }
    }                                
    int k=2; int count=0;
    while(m>=0){
    	for(int z=2;z<=k;z++){
            m--;
        }
        if(a[k-1]<a[k])a[k-1]++;
        else if(a[k-1]==a[k]) {
            k++;
            count++;
        }
    }                                
    cout<<count;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
