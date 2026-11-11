#include<bits/stdc++.h>
using namespace std;
int n,a,lon,ans;
char c,s[100005];

int main(){
	freopen("string.in","stdin");
	freopen("string.out","stdout");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=lon;j<lon+a;j++){
			s[j]=c;
		}
		lon+=a;
	}
	//
	int l=lon/2-1,r;
	if(lon%2==0) r=lon/2;
	else r=lon/2+1;
	//
	for(int i=0;i<lon/2;i++){
		if(s[l]!=s[r]) ans++;
		l-=1;
		r+=1;
	}
	cout<<ans;
	return 0;
} 
