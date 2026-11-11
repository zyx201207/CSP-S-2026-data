#include<bits/stdc++.h>
using namespace std;
int n;
const int MM=2*1e5+100;
int a[MM];
char c[MM];
string sss;
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ttt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		bool pdpd=0;
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
			pdpd=1;
		}
		if(!pdpd){
			for(int j=ttt;j<=ttt+a[i];j++){
				sss[j]=c[i];
			}
			ttt+=a[i];
		}
		
	}
	ttt-=1;
	if(ttt%2==1){
		int midd=ttt/2;
		for(int i=1;i<=midd;i++){
			if(sss[i]!=sss[ttt-i+1]){
				ans++;
			}
		}
	}
	else{
		int midd=ttt/2;
		for(int i=1;i<=midd;i++){
			if(sss[i]!=sss[ttt-i+1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
