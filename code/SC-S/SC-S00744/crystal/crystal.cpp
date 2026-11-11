#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans=1,sum=1,s,y;
void ss(int x){
	int c=s,cc=sum;
	for(int o=x;o<n;o++){
		s=c;
		sum==cc;
		if(y-a[o]>=s){
			sum+=1;
			s-=(y-a[o]);
			ans=max(ans,sum); 
			ss(o+1);
		} 
		else return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n,greater<int>());
	y=a[1]-a[2];
	for(int i=1;i<=n;i++){
		m-=i*y;
		if(m>=0) ans++;
		else break;
	}
	cout<<ans;
} 