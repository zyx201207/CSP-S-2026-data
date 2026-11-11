# include <bits/stdc++.h>
using namespace std;
int a[200005];
string b[200005];
string ej(int x){
	string s="";
	while(x){
		int gw=x%2;
		x/=2;
		if(gw) s+="1";
		else s+="0";
	}
	string ss="";
	for(int i=0;i<s.size();i++){
		ss+=s[s.size()-i-1];
	}
	return ss;
}
string awy(string x,string y){
	string ans="";
	for(int i=0;i<min(x.size(),y.size());i++){
		if(x[i]==y[i]&&x[i]=='1'){
			ans+="1";
		}else{
			ans+="0";
		}
	}
	return ans;
}
int sz(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans=ans*10+(s[i]-'0');
	}
	return ans;
}
int hl(int sz){
	int ans=0;
	int k=0;
	while(sz){
		int gw=sz%10;
		sz/=10;
		ans+=gw*pow(2,k);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int n,m,maxh=-1;
	int ans=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxh=max(maxh,a[i]);
		b[i]=ej(a[i]);
	}
	if(m==1){
		cout<<maxh;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,sz(awy(b[i],b[j])));
			}
		}
		cout<<hl(ans);
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++){
			b[i]=awy(b[i],b[i-1]);
		}
		cout<<hl(sz(b[n-1]));
		return 0;	
	}
	if(m==n-1){
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				if(b[j]==b[i]){
					b[j+1]=awy(b[j+1],b[j-1]);
					j++;
					continue;
				}
				b[j]=awy(b[j],b[j-1]);
			}
			ans=max(ans,hl(sz(b[n-1])));
		}
		cout<<ans;
		return 0;
	}
	
	
	return 0;
}
