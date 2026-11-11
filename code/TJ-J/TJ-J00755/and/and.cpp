#include<bits/stdc++.h>//and
using namespace std;
int n,m,a[200005],b[50];
int ma;
int to_do(){
	bool fla=1;
	int s;
	for(int i=1;i<=n;i++){
		if(b[i]){
			if(fla){
				fla=0;
				s=a[i];
			}
			else s= s & a[i];
		}
	}
	return s;
}
void dp(int c){
	if(c==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=b[i];
		}
		if(cnt==m){
			ma=max(ma,to_do());
		}
		return ;
	}
	else {
		for(b[c]=0;b[c]<=1;b[c]++){
			dp(c+1); 
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else if(m==2){
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				int k=a[i] & a[j];
				ma=max(ma,k);
			}
		}
		cout<<ma;
	}
	else if(m==n){
		bool fla=1;
		ma=a[1];
		for(int i=2;i<=n;i++){
			ma= ma & a[i];
		}
		cout<<ma;
	}
	else if(n<=20){
		dp(1);
		cout<<ma;
	}
	else cout<<0;
	
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
