#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[200010],b[200010],s;
void yyy(int t,int h){
	if(t>m){
		int k=b[1];
		for(int i=2;i<=m;i++){
			k=k&b[i];
		}
		if(k>s)s=k;
		
	}
	else for(int i=h;i<=n;i++){
			b[t]=a[i];
			yyy(t+1,i+1);
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	yyy(1,1);
	cout<<s;
	return 0;
}
