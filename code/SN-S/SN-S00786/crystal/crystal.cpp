#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005],cnt,x,mx;
	cin>>n>>m;
	x=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(m-(a[i]-a[j])<0)break;
				else {
					cnt+=1;
					m=m-(a[i]-a[j]);
				}
					
		}
		m=x;
		mx=max(cnt,mx);
		cnt=0;
	}
	cout<<mx;
	return 0;
} 
//5 8
//-3 -1 2 2 7
