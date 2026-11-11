#include<bits/stdc++.h>
using namespace std;
long long n,m,nm[1000005]={},mm[1000005]={},mx[1000005]={},nn[1000005]={},d=1,a=-1,a1=1;
void pop(){
	a=d;
	for(int i=a1;a1<a;i++){
	mx[nn[i]]--;
	}
	a1=a;
}
void push(int x){
	nn[d]=x;
	d++;
	mx[x]++;
	for(int i=1;i<=m;i++){
	 if(mx[i]>=2)pop();
	 mx[i]=1;
	}
}

void sjq(){
	for(int i=1;i<=m;i++){
	 if(mx[i]!=0)
	 mm[i]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
	}
	for(int i=n;i>=1;i--){
		for(int f=1;f<=i;f++){
		push(nm[f]);
	}
	for(int f=a;f<=d;f++){
		mm[nn[f]]++;
		}
	}
	for(int i=1;i<=m;i++){
	 cout<<mm[i]<<' ';
	}
	return 0;
}
