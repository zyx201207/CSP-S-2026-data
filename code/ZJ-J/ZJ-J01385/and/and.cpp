#include<bits/stdc++.h>
using namespace std;
int a[200010];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	
	if(m==1){
		cout<<mx;
		return 0;
	}
	
	int s=a[1];
	if(m==n){
		for(int i=1;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	
	int ms=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				else ms=max(a[i]&a[j],ms);
			}
		}
		cout<<ms;
		return 0;
	}
	
	int mk=-1;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int ml=a[i+1];
			if(i==n)ml=a[1];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else ml=ml&a[j];
			}
			mk=max(ml,mk);
		}
		cout<<mk;
		return 0;
	}
	return 0;
}
