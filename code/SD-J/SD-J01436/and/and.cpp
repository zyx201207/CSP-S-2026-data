#include<bits/stdc++.h>
using namespace std;
string x[200100];
long long aa[200100];
int tt[200010][35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	long long xx,t=1,c=0,cnt;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>xx;
		while(xx){
			if(xx%2==0) x[i]+="0";
			else x[i]+="1";
			xx/=2;
		}
		while(x[i].size()<31){
			x[i]+="0";
		}
		reverse(x[i].begin(),x[i].end());
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<x[i].size();j++){
			tt[i][j]=tt[i-1][j];
			if(x[i][j]=='1') tt[i][j]++;
		}
		if(i>=k){
			t=1;
			cnt=0;
			for(int j=x[i].size()-1;j>=0;j--){
				if(tt[i][j]-tt[i-k][j]==k) cnt+=t;
				t*=2;
			}
			c=max(c,cnt);
		}	
	}	
	cout<<c;
	return 0;
} 
