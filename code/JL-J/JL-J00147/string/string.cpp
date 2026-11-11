#include<bits/stdc++.h>
using namespace std;	
string x[6000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,y=1,z,j=0,k=2;
	cin>>n;
	long long s[n+10];
	string p[n+10];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		m=m+s[i];
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=s[i];l++){
			x[y]=p[i];
			y++;
		}
	}
	if(m%2==0){
		z=m/2+1;
	}else z=(m+1)/2+1;
	for(int i=z;i<=m;i++){
		if(x[i]==x[i-k]) k=k+2;
		else{
			k=k+2;
			j++;
		}
	}
	cout<<j;
}
