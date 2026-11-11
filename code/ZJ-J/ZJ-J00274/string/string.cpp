#include<bits/stdc++.h>
using namespace std;

int n,a,z;
long long ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	while(n--){
		cin>>a>>c;
		z+=a;
		while(a--) s+=c;
	}
	for(long long i=0;i<z/2;i++){
		if(s[i]!=s[z-1-i]) ans++;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

