#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l=1,he=0,d=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=1){
			he=(he+(a[i]-a[i-1])*(i-1-l+1));
		}
		while(he>m){
			he=(he-(a[i]-a[l]));
			l++;
		}
		d=max(d,i-l+1);
	}
	cout<<d<<'\n';
	return 0;
}
