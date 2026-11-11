#include<bits/stdc++.h>

using namespace std;
long long d [300000];
char f[300000];
char s[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,shn=0,zn=0,y=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>f[i];
		shn+=d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[i];j++){
			//cout<<f[i];
			s[y]=f[i];
			y++;
		}
	}
	long long r=1,l=y,h=y;
	
//	for(int i=2;i<=y;i++){
//		if(s[i]==s[i-1]) h--;
//	}
//	if(h==0){
//		cout<<0;
//		return 0;
//	}
	while(r!=y/2&&l!=y/2){
		if(s[r]!=s[l]){
			ans++;
			//cout<<s[r]<<s[l];	
		}
		r++;
		l--;
	}
	
	
	cout<<ans;
	//for(int i=1;i<=y;i++){
	//	cout<<s[i];
	//}
	return 0;
	//It's~okay!
}

