#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,cha;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n-1;i++){
		cha=a[i+1]-a[i];
		m-=cha*(i+1);
		if(m<0){
			cout<<cnt;
			return 0;
		}
		cnt++;
	}
	return 0;
}
