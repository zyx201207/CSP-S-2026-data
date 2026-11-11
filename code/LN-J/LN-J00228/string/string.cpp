#include<bits/stdc++.h>
using namespace std;
int n;
char b[100000002];
long long sum=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int cnt1;
        char a;
        cin>>cnt1>>a;
        for(int j=cnt;j<cnt+cnt1;j++){
            b[j+1]=a;
        }
        cnt+=cnt1;
    }
    for(int i=1;i<=cnt/2;i++){
        if(b[i]!=b[cnt+1-i]){
            sum++;
        }
    }
    cout<<sum<<'\n';
    return 0;
}
