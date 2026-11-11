#include<bits/stdc++.h>
using namespace std;
long long x[300000];
char y[300000];
string s;
long long ans=0,sum=0,f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		sum+=x[i];
	}
	for(int i=1;i<=n;i++){
		if(y[1]!=y[i]) f=0;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			s+=y[i];
		}
	}
	for(int i=0;i<sum/2;i++){
			if(s[i]!=s[sum-i-1]){
				ans++;
			}
		}
		cout<<ans;
	return 0;
}//×¢Òâm n 
