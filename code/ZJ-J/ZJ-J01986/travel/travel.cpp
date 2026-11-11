#include<bits/stdc++.h>
using namespace std;
typedef long long bro;
string c,s,cc,ss,ans,x,y;
char a,b;
bro p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c == cc){
		ans += '1';
	}else{
		ans += "0000";
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 0;i < 2;++i){
		x += s[i];
		y += ss[i];
	}
	a = s[2];
	b = ss[2];
	if(x == y){
		ans += '1';
	}else{
		ans += "000";
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(a == 'A' || a == 'B' || a == 'C'){
		p = 1;
	}
	if(b == 'A' || b == 'B' || b == 'C'){
		q = 1;
	}
	if(p == q){
		ans += '1';
		if(p == 0 && q == 0){
			ans += '1';
		}else if(abs(a-b) == 1){
			ans += '1';
		}else{
			ans += '0';
		}
	}else{
		ans += "00";
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}