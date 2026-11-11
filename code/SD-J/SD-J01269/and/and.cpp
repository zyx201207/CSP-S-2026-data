#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7; 
int t[35],ans,a[N][35];
int n,m;


int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		string s;
		while(x){
			s+=x%2+'0';
			x/=2;
		}
		int len=s.size();
		for(int j=0;j<len;j++){
			a[i][j]=s[j]-'0';
		}
	}
	
	
	for(int i=1;i<m;i++){
		for(int j=0;j<=31;j++){
			t[j]+=a[i][j];
		}
	}
	
//	for(int i=0;i<5;i++){
//		cout<<t[i];
//	}
	
	
	for(int i=m;i<=n;i++){
		for(int j=0;j<31;j++){
			t[j]+=a[i][j];
			t[j]-=a[i-m][j];
		}
		
		for(int j=0;j<5;j++){
			cout<<t[j];
		}cout<<endl;
		
//		int c=1,sum=0;
//		for(int j=0;j<=31;j++){
//			if(t[j]==m){
//				sum+=c;
//			}
//			c*=2;
//		}
//		ans=max(ans,sum);
	}
	cout<<ans;
	
	
}
