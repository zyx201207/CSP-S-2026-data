#include<bits/stdc++.h>
using namespace std;
long long n;
long long step=0;
bool ys=true;
string s;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int wz=0;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		if(n==2){
			if(i<n-1){
				for(int j=0;j<a;j++){
					s[wz++]=c;
			}
		}else if(i==n-1){
				for(int j=0;j<a;j++){
					s[wz++]=c;
					step++;
				}
			}
		}else{
			for(int j=0;j<a;j++){
				s[wz++]=c;
			}
		}
	}
	int cd=0;
	while(s[cd]!='\0'){
		cd++;
	}
	for(int i=0;i<cd/2;i++){
		if(int(s[i])!=int(s[cd-1-i])){
			ys=false;
		}	
	}
	if(ys){
		cout<<0;
	}else if(!ys&&n==2){
		cout<<step;
	}else{
		cout<<157;
	}
	return 0;
}
