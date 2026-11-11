#include <bits/stdc++.h>
#define int long long
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define Auto(v,a) for(auto v:a)
#define ps() putchar(' ')
#define pe() putchar('\n')
using namespace std;
const int N=1e5+10;
void read(int &x){
	int a=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()){
		if(c=='-'){
			f=-1;
		}
	}
	for(;isdigit(c);c=getchar()){
		a=a*10+c-48;
	}
	x=a*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
bool f(string x,string y,int s,int e){
	rep(i,s,e){
		if(x[i]!=y[i]){
			return false;
		}
	}
	return true;
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='F'){
		s1[2]--;
	}
	if(s2[2]=='F'){
		s2[2]--;
	}
	if(c1==c2){
		write(1);
	}
	else{
		rep(i,1,4){
			putchar('0');
		}
		return 0;
	}
	if(f(s1,s2,0,1)){
		write(1);
	}
	else{
		rep(i,1,3){
			putchar('0');
		}
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
		write(1);
	}
	else{
		rep(i,1,2){
			putchar('0');
		}
		return 0;
	}
	if((s1[2]-s2[2]==1||s2[2]-s1[2]==1)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
		write(1);
	}
	else{
		write(0);
	}
	return 0;
}


