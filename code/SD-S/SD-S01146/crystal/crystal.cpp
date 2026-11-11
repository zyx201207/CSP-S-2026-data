#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
template<typename T>void read(T& x){
	T res=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c)){
		res*=10;
		res+=c-'0';
		c=getchar();
	}
	x=res*f;
}
void read(){
	
}
template<typename T1,typename... Ts>void read(T1& x,Ts&... xs){
	read(x);
	read(xs...);
}
template<typename T>void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
void write(){
	
}
template<typename T1,typename... Ts>void write(T1 x,Ts...xs){
	write(x);
	putchar(' ');
	write(xs...); 
}
#define el putchar('\n')
#define sp putchar(' ')
#define ll long long
const int MAXN=5e5+5;
ll n,m;
ll a[MAXN];
queue<int> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n,m);
	for(ll i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1);
	ll sum=0,cur=a[1],ans=1;
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		while(sum+(a[i]-cur)*q.size()>m){
			int t=q.front();
			sum-=cur-t;
			q.pop();
		}
		sum+=(a[i]-cur)*q.size();
		cur=a[i];
		q.push(a[i]);
		ans=max(ans,(ll)q.size()*1ll);
	}
	write(ans);
	el;
	return 0;
}
/*
14:12 12min: 打完缺省源 
15:00 30min: T1想了二分,发现没有单调性,舍去 
15:19 50min: T1大样例过了,思路应该对 
*/
