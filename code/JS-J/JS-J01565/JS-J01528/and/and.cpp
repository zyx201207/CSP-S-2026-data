#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w", stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long int num=a[n-1];
    m-=1;
    for(int i=n-2;i>=0;i--){
        if(m==0){
            break;
        }
        m--;
        cout<<num<<"      "<<a[i]<<"                ";
        num&=a[i];
    }
    cout<<num<<"\n";
    return 0;
}
