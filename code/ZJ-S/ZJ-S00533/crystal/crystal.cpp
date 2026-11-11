#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],mx,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int m1=m;
	for(int i=1;i<=n;i++){
		s=1;
		for(int j=i-1;j>0;j--){
			if(m>=(a[i]-a[j])){
				m-=a[i]-a[j];
				s++;
			}else{
				break;
			}
		}
		mx=max(mx,s);
		m=m1;
	}
	cout<<mx;
}
