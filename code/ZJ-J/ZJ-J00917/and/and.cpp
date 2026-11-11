#include<bits/stdc++.h>
using namespace std;
long long n,m,ju,l,r,mid;
long long wei[50],a[300000],t,ans,yangli7,maxn,yangli13;
long long dam=0,deep;
bool A,B;
priority_queue<long long>pq;
bool check(int mid){
	dam=0;
	for(int i=1;i<=n;i++) if((a[i]&mid)==mid) dam++;
	if(dam>=m) return true;
	return false;
}
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	A=true;B=true;
	n=read(),m=read();
	a[1]=read();pq.push(a[1]);
	yangli7=a[1];
	if(((a[1]+1)&a[1])!=0) A=false;
	if(a[1]!=0) B=false;
	for(int i=2;i<=n;i++){
		a[i]=read();
		pq.push(a[i]);
		if(((a[i]+1)&a[i])!=0) A=false;
		if(a[i]!=i-1) B=false;
	}
	for(int i=1;i<=n;i++){
		t=pq.top();
		pq.pop();
		a[i]=t;
	}
	t=a[1];
	for(int i=31;i>=1;i--){
		if(((1<<i)&t)==(1<<i)){
			ju=i;
			break;
		}
	}
	for(int i=1;i<=ju;i++){
		for(int j=1;j<=n;j++){
			if(a[j]&(1<<i)==(1<<i)){
				wei[i]++;
			}
		}
	}
	for(int i=ju;i>=1;i--){
		if(wei[i]>=m){
			ju=i;
			break;
		}
	}
	if(A|B){
		yangli13=a[1];
		for(int i=2;i<=m;i++){
			yangli13=yangli13&a[i];
		}
		cout<<yangli13;
	}else{
		l=ju,deep=2;
		for(int i=ju;i<=(1<<ju);i++){
		if(check(i)){
			l=i;
		}
		deep*=2;
	}
	cout<<l;
	}
	return 0;
}
