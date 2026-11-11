#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];
long long ans=-1;

bool cmp(long x,long long y){
	return x>y;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i;j<n;j++){
				if(a[j]&a[j-1]>ans){
					ans=a[j]-a[j-1];
				}
			}
		}
	}
	else if(m!=2){
		while(m){
			for(int q=2;q<n;q++){
				if(a[q]&a[q-1]&a[q-2]>ans){
					ans=a[q]&a[q-1]&a[q-2];
				}
			}
		}
		m--;
	}
	cout<<ans;
	
	return 0;
}
