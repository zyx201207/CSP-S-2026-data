#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=0;i<n;i++){
			ans&=a[i]&a[i+1];
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n+1);
	int maxa=-0x3f3f3f3f;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((a[j]&a[i])>=maxa){
				maxa=(a[j]&a[i]);
			}
		}
	}
	if(m>2){
		cout<<maxa/2;
		return 0;
	} 
	if(m==1){
		cout<<a[0];
	}
	cout<<maxa;
	return 0;
} 
