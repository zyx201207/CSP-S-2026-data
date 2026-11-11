#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[100005];


    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++){
        long long m_min=0;
        if(a[i]>a[i+1]){
            m_min=a[i];
        }
        else{
            m_min=a[i+1];
        }
        if(i==n-2){
            cout<<m_min;
        }
    }














return 0;
}
