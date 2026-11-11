#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d=0,e,r[1000000],t,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
cin>>a>>b;
for(int i=1;i<=a;i++){
	cin>>r[i];
	d=max(d,r[i]);
} 
if(b==1){
	cout<<d;
	return 0;
}
if(a==b){
	t=r[1];
	for(int i=2;i<=a;i++){
		t=t&r[i];
	}
	cout<<t;
	return 0;
}
if(b==2){
	for(int i=1;i<=a-1;i++){
		for(int j=i+1;j<=a;j++){
			m=r[i]&r[j];
			t=max(t,m);
		}
	}
	cout<<t;
	return 0;
}
if(b==a-1){
	for(int i=1;i<=a;i++){
		if(i==1){
			m=r[2];
		}else{
			m=r[1];
		}
		for(int j=2;j<=a;j++){
			if(i==1 and j==2){
				continue;
			}
			if(j==i){
				continue;
			}
			m=m&r[j];
		}
		t=max(t,m);
	}
	cout<<t;
	return 0;
}
	return 0;
} 
