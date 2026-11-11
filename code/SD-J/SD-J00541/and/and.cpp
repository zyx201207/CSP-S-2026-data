#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,ml;
ll a[N];
void f2(){
	int q=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			int qwe=a[i]&a[j];
			q=max(qwe,q);
		}
	}cout<<q;
}
void f(){
	int q=0,qwe=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=3){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=4){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=5){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=6){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=7){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=8){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=9){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}qwe=0;
	for(int i=1;i<=n;i+=10){
		for(int j=1;j<i;j++){
			qwe=qwe&a[j];
		}q=max(qwe,q);
	}cout<<q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ml=max(ml,a[i]);
	}
	if(n<=2000){
		if(m==1){
			cout<<ml;
		}else if(m==2){
			f2();
		}else if(m==n){
			int q=0;
			for(int i=1;i<=n;i++)
				q&=a[i];
			cout<<q;
		}
		else{
			f();
		}
	}else{
		if(m==1){
			cout<<ml;
		}else if(m==2){
			f2();
		}else if(m==n){
			int q=0;
			for(int i=1;i<=n;i++)
				q&=a[i];
			cout<<q;
		}
		else{
			int qwe=0,q=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<n,j!=i;j++){
					qwe=qwe&a[j];
				}q=max(q,qwe);
			}cout<<q; 
		}
	}
	return 0;
}

