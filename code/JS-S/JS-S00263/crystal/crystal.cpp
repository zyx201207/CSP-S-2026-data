#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,m;
int a[N];
int chaf[N];
ll qian[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
		chaf[i]=a[i]-a[i-1];
        qian[i]=qian[i-1]+(i-1)*chaf[i];
    }
    qian[n+1]=LLONG_MAX;
    for(int i=n+1;i>=2;i--){
        if(m<qian[i]&&m>=qian[i-1]){
            cout<<i-1;
            return 0;
        }
    }
}
