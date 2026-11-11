#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int s[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+n+1,cmp);
    int sum=a[1];
    for(int i=2;i<=m;i++){
    	sum&=a[i];
	}
	cout<<sum;
    return 0;
}

