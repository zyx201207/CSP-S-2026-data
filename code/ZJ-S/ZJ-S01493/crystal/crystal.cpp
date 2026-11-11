#include<bits/stdc++.h>
using namespace std;
#define LL __int128
const int N=5e5+5;
const LL inf=1e17;
LL in(){
	LL aa=0,bb=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=(aa<<3)+(aa<<1)+(cc^48);
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}
LL a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n=in(),m=in(),ans=1,num=m,lft=1;
	LL cnt=1;
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	sort(a+1,a+n+1);
	//a[n+1]=inf;
	for(LL i=2;i<=n;i++){
		cnt++;
		num-=(a[i]-a[i-1])*(i-lft);
		while(num<0){
			cnt--;
			num+=a[i]-a[lft];
			lft++;
		}
		ans=max(ans,cnt);
	}
	out(ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
