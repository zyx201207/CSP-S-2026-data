#include<bits/stdc++.h>
using namespace std;

int a[100000000];
int b[100000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,w=0,e;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            b[w]=a[i+j]&&a[i+j+1];
            w++;
            if(a[i]=='0'){
                break;
            }
        }
        for(int h=0;h<m;h++){
            e=max(b[1+h],b[2+h]);
        }
    }
    cout<<e;
    return 0;
}
