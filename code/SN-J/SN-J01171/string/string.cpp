#include<bits/stdc++.h>
using namespace std;
long long n,ans,m;
char s[1000000005];
void hw(char s[]){
	bool f=1;
	for(int i=0;i<=strlen(s)/2;i++){
		if(s[i]!=s[strlen(s)-i-1]){
				f=0;
				ans++;	
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char len;
		cin>>x>>len;
		for(int j=1;j<=x;j++){
			s[m]=len; 
			m++;
		}	
	}
	hw(s);
	return 0;
} 
