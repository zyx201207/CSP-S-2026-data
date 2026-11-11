#include<bits/stdc++.h>
using namespace std;
long long n,ai,x,y,ans;
char ci;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>ai>>ci;
		while(ai--){
			s[y]=ci;
			y++;
		}
	}
	y-=1;
	while(x!=y){
		if(s[x]!=s[y]){
			ans++;
		}
		x++;
		y--;
	}
	cout<<ans;
	fclose(sdin);
	fcluse(stdout);
	return 0;
}
