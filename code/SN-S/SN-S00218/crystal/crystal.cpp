#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int zsmax=0,zs;
	while(true){
		int b,c=a[1]-a[0];
		for(int i=1;i<n-1;i++){
			if(c==0||c<0){
				c=a[i+1]-a[i];
				continue;
			} 
			if(a[i+1]-a[i]<c&&a[i+1]-a[i]!=0){
				c=a[i+1]-a[i];
				b=i;
			}
		}
		for(int i=0;i<n;i++){
			zs=1;
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j]){
					zs++;
				}
			}
			if(zs>zsmax){
				zsmax=zs;
			}
		}
		if(m>=c){
			a[b]+=c;
			m-=c;
		}
		else{
			break;
		}
	}
	cout<<zsmax+2;
	return 0;
}
