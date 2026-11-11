#include<bits/stdc++.h>
using namespace std;
long long n,m,s,a[500010],ss,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j>=1;j--){
			s+=a[i]-a[j];
			if(s>m){
				x=i-j;
				break;
			}
		}
		if(s<=m){
			ss=i;
		}else if(x>ss){
			ss=x;
		}
	}
	cout<<ss;
    return 0;
}