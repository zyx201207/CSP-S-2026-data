//张宸熙 西安市第十二中学 SN-S00366
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],s,b,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s+=a[n]-a[i];
	}
	if(s<m){
		cout<<n;
	}else{
		long long min=1e18,id;
		b/=n;
		for(int i=1;i<=n;i++){
			if(abs(a[i]-b)<min){
				min=abs(a[i]-b);
				id=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(m==0){
				for(int j=1;j<=n;j++){
					if(a[j]==a[id]){
						cnt++;
					}
				}
				cout<<cnt;
				return 0;
			}
			if(a[i]<a[id]){	
				if(a[id]-a[i]<=m){
					m=m-(a[id]-a[i]);
					a[i]=a[id];
				}else{
					for(int j=1;j<=n;j++){
						if(a[j]==a[id]){
							cnt++;
						}
					}
					cout<<cnt;
					return 0;
				}
			}
		}	
	}
}
