#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string s[200010];
string er(int a){
	string s;
	while(a){
		if(a%2==0){
			s='0'+s;
		}else{
			s='1'+s;
		}
		a/=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		long long ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		/*char d;
		sort(a,a+n);
		for(int i=0;i<n;i++){
			long long c=a[i];
			while(c){
				d=c%2;
				s[i]+=d;
				c/=2;
			}
		}
		for(int i=0;i<21;i++){
			int e[m];
			for(int i=)
		}*/
		for(int i=0;i<n;i++){
			s[i]=er(a[i]);
			cout<<s[i]<<endl;
		}
		for(int i=0;i<21;i++){
			int cnt=0;
			bool e[200010];
			int d=0;
			for(int j=0;j<n;j++){
				if(s[i][j]=='1'){
					cnt++;
					e[d++]=1;
				}
			}
			if(cnt=m){
				int ans=a[e[0]];
				for(int i=1;i<d;i++){
					ans&=a[e[i]];
				}
				cout<<ans;
				return 0;
			}
		}
	}
	
	
	
	
	
	
	
}
