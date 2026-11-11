#include<bits/stdc++.h>
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		x = (x<<3)+(x<<1)+c-'0';
		c = getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x = -x;
	}
	if(x<10){
		putchar(x+'0');
	}
	else {
		write(x/10);
		putchar(x%10+'0');
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	string ans = "";
	if(c1 == c3)ans += "1";
	else ans += "0";
	char l1 = c2[0]+c2[1];
	char l2 = c4[0]+c4[1];
	if(ans[0] == '0')ans += "0";
	else if(l1 == l2)ans += "1";
	else ans += "0";
	char r1 = c2[2],r2 = c4[2];
	if(ans[1] == '0')ans += "0";
	else if(r1<='C' && r2<='C')ans += "1";
	else if(r1>='D' && r2>='D')ans += "1";
	else ans += "0";
	if(ans[2] == '1'){
		if(abs(r1-r2) == 1){
			if(r1>r2)swap(r1,r2);
			if(r1 == 'C' && r2 == 'D'){
				ans += "0";
			}
			else ans += "1";
		}else ans += "0";
	}else ans += "0";
	cout<<ans<<"\n";
	return 0;
}
