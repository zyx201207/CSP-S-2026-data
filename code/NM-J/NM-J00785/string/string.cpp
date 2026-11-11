#include<bits/stdc++.h>

using namespace std;
string a,b[200005];
long long c,d,n,ans,e,f;
int main(){
	freopen(string.in,"r",stdin);
	freopen(string.out,"w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>c>>b[i];
		if(i!=0&&b[i]==b[i-1]){
			e+=c;
		}
		else if(i==0){
			e+=c;
		}
		else if(i==n-1){
			if(f==0)
			{
				cout<<0;
				return 0;
			}			
			for(int j=0;j<e;j++){
				a+=b[i-1];
			}
			d+=c;
		}
		else{
			for(int j=0;j<e;j++){
				a+=b[i-1];
			}
			d+=c;
			f=1;
		}
	}
	for(long long i=0;i<=d/2;i++){
		if(a[i]!=a[d-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
