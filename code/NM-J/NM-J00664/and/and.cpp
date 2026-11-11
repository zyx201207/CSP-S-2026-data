#include<bits/stdc++.h>
using namespace std;
string xxx(int a){
	string ax,al;
	while(a>0){
		ax+=a%2+'0';
		a=a/2;
	}
	int v=ax.size();
	for(int i=v-1;i>=0;i--){
		al+=ax[i];
	}
	return al;
}
int xpro(string a,string b){
	int al=a.size(),bl=b.size();
	string x;
	for(int i=0;i<min(al,bl);i++){
		if(a[i]=='1'&&b[i]=='1'){
			x+='1';
		}
		else{
			x+='0';
		}
	}
	int xl=x.size(),ans=0,v=0;
	for(int i=xl-1;i>=0;i--){
		ans+=(x[i]-'0')*pow(2,v);
		v++;
	}
	return ans;
}
int a[500010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	int b[500010],bl=0;
	for(int i=n-1;i>=n-m;i--){
		b[bl]=a[i];
		bl++;
	}
	string al=xxx(b[0]),cl=xxx(b[1]);
	int ans=xpro(al,cl);
	for(int i=2;i<m;i++){
		ans=xpro(xxx(ans),xxx(b[i]));
	} 
	cout<<ans;
	return 0;
} 
