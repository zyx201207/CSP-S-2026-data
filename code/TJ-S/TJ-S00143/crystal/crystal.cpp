#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10; 
long long n,m,a[N]={0},r=1,y=0,k[N]={0},u=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long w=abs(a[2]-a[1]);
	bool flag=true;
	long long x=0;
	for(int i=2;i<=n;i++){
		if(a[i-1]+w!=a[i]){
			flag=false;
		}
	}
	if(flag){
		y=w;
		while(m>=w){
			m-=w;
			w+=y;
			r++;
		}
		if(r>n){
			r=n;
		}
		cout<<r;
	}else{
		for(int i=2;i<=n;i++){
			u=0;
			y=0;
			for(int j=i;j>=1;j--){
				if(u+a[i]-a[j]<=m){
					y++;
					u=u+a[i]-a[j];
					x=max(x,y);
				}else{
					break;
				}
			}
		}
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
