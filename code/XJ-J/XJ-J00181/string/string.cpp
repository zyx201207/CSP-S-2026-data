#include <bits/stdc++.h>
using namespace std;
string S;
long long ans,lon;
long long i,j;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n;
	cin >> n;
	int z=0,flg=0;
	for(i=1;i<=n;i++){
		long x=0;
		int y=0;
		string s;
		cin >>x>> s;
		y= s[0] -'a' + 1;
		if(z == 0){
			z = y;
		}else if(z!=y){
			flg = 1;
		}
		for(j=1;j<=x;j++){
			S=S+s;
		}
		lon+=x;
	} 
	if(flg == 0){
		cout<< 0;
		return 0;
	}
	for(i = 0; i<(lon-1)/2;i++){
		if(S[i] == S[lon-i-1]){
			continue;
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
