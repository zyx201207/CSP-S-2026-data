#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],pp,l=0,b[200005];
string s[200005];
void bb(int i){
	s[i]="000000000000000000000000000000000000";
	int w=a[i];
	int cnt=0;
	while(w){
		s[i][++cnt]=w%2+'0';
		w/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bb(i);
	}bool ww=0;
	for(int i=32;i>=1;i--){
		int cnt=0;
		if(!ww){
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1'){
					cnt++;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1'&&b[j]==l){
					cnt++;
				}
			}
		}
		if(cnt>=m&&ww==0){
			ww=1;l++;
			pp+=(1<<i-1);
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1'){
					b[j]=l;
				}
			}
		}else if(cnt>=m&&ww){
			pp+=(1<<i-1);
			l++;
			for(int j=1;j<=n;j++){
				if(s[j][i]=='1'&&b[j]==l-1){
					b[j]=l;
				}
			}
		}
	}
	if(ww==0)cout<<0;
	else cout<<pp;
	return 0;
} 
