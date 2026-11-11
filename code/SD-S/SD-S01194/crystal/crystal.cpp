#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int SIZE=5e5+10;
ll n,m,ans;
ll a[SIZE],b[SIZE],s[SIZE],ss[SIZE],f[SIZE],ff[SIZE];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[i]=a[i+1]-a[i];
		//		cout<<b[i]<<' ';
				s[i]=s[i-1]+b[i];
		//		cout<<s[i]<<' ';			
				ss[i]=ss[i-1]+s[i];	
		//		cout<<ss[i]<<' ';	
			}
			for(int j=i;j<n;j++){
				f[i]=i*s[i]-ss[i-1];
				ff[i+1]=f[i];
				ans=j;
				if(m<ff[i]){
					cout<<i-1;
					return 0;
				}	
			}				
	}
	cout<<ans;
	return 0;	
	}
	else{
		for(int i=1;i<=n;i++){
			b[i]=a[i+1]-a[i];
	//		cout<<b[i]<<' ';
			s[i]=s[i-1]+b[i];
	//		cout<<s[i]<<' ';			
			ss[i]=ss[i-1]+s[i];	
	//		cout<<ss[i]<<' ';	
		}
		ff[1]=0;ff[2]=b[1];
		for(int i=2;i<n;i++){
			f[i]=i*s[i]-ss[i-1];
			ff[i+1]=f[i];
	//		if(m<ff[i]){
	//			cout<<i;
	//			return 0;
	//		}	
		}
//		for(int i=1;i<=n;i++){
//			cout<<ff[i]<<' ';		
//		}
		ll it=0;
		while(m>=ff[it]&&it<=n){
			it++;
		}
	//	cout<<m<<endl;
	//	cout<<ss[n-1]<<endl;
		cout<<it-1;		
	}
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 4
-10 1 5 6 10
*/
