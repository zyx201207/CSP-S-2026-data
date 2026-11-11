#include<bits/stdc++.h>
using namespace std;
int a[200010],js[400010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("stdin.in","r",stdin);
    freopen("stdin.out","W",stdout);
    int n,m;
    cin>>n>>m;
    int num=0,num1=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++){
            int k=j+1;
            while(k<n&&num<m){
                js[i+j+k]=a[j]%a[k];
                k++;
                num++;
            }
        }
    }
    sort(js[0],js[n+1]);
    cout<<js[num+1];
    return 0;
}
