#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=-0x3f3f3f3f,an;
	if(m==1){
		cout<<a[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){

			for(int j=2;j<=n;j++){
				if(j==2){
					if(i==1){
						an=a[2];
					}
					else{
						an=a[1];
					}
				}
				if(j!=i){
					an=(an&a[j]);
				}
				
			}
			ma=max(ma,an);
		}
	}
	else if(m==n){
		an=a[1];
		for(int i=2;i<=n;i++){
			an=(an&a[i]);
		}
		cout<<an;
	}
	else{
		an=a[n];
		int cnt=0;
		for(int i=n-1;i>=1;i--){
			cnt++;
			an=(an&a[i]);
			if(cnt==m-1)break;
		}
		cout<<an;
	}
	return 0;
} 
