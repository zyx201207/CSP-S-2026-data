#include <bits/stdc++.h>
using namespace std;
long long int n=0,m=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a,a+n);
    long long int _max=0;
    for(int i=0;i<n;i++){
        long long int m1=m,k=a[i],_max_=0;
        for(int j=i;j>=0;j--){
            if(a[i]-a[j]<=m1){
                m1-=a[i]-a[j];
                _max_+=1;
            }
            _max=max(_max,_max_);
        }
    }
    cout << _max << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
