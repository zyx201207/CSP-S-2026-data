#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int d1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>d1){
			d1=a[i];
		}
	}
	if(m==1){
		cout<<d1<<endl;
		return 0; 
	}
	if(m==n){
		int b=a[1]&a[2];
		for(int i=3;i<=n;i++){
			b=b&a[i];
		}
		cout<<b<<endl;
		return 0;
	}
	if(m==2){
		int px=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				} 
				if(a[i]&a[j]>px){
					px=a[i]&a[j];
				}
			}
		}
		cout<<px<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1]<<endl;
	return 0;
}
//7199
//按位与：11为1 
