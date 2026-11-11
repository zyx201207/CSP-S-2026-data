#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5;

ll in(){
	char c=getchar();
	ll num=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	return num*f;
}

void out(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10) putchar(x+'0');
	else{
		out(x/10);
		putchar(x%10+'0');
	}
}

ll n,m,ans,cnt,num,cost;//cnt the num of be chosen£¬num the a_i of be chosen£¬cos is the m have be used 
ll a[N]; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	sort(a+1,a+n+1);
	int j=0;//the id of have be throw
	for(int i=1;i<=n;i++){
		cost+=cnt*(a[i]-num);
		num=a[i];cnt++;
		while(cost>m){
			j++;
			cost-=(num-a[j]);
			cnt--;
		}
		ans=max(ans,cnt);
	}
	out(ans);
	printf("\n");
	
	return 0;
}

//-g3 ¹Ø×¢zgmbsydmzÐ»Ð»ß÷~ 



 
