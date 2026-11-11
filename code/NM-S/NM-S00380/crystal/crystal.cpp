#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,s=1,t;
	cin >> n >> m;
	for(i=1;i<=n;i++){
        cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(i=2;;i++){
        if((a[i]-a[i-1])*(i-1)<=m){
            s++;m-=(a[i]-a[i-1])*(i-1);
        }else{
            break;
        }
	}
	cout << s;
	return 0;
}
