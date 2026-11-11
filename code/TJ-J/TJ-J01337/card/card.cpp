#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d[1000000],e,r,t[1000000];
void qing(int x){
	for(int i=1;i<=r;i++){
		if(x==d[i]){
			for(int j=i;j<=r;j++){
				d[j]=0;
			}
			r=i;
			return ;
		}
	}
	return ;
}
void q(){
	for(int i=1;i<=r;i++){
		d[i]=0;
	}
	return ;
}
void df(){
	for(int i=1;i<=r;i++){
		t[d[i]]++;
	} 
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	for(int i=1;i<=a;i++){
		r=0;
		for(int j=i;j<=a;j++){
			qing(c[j]);
			r++;
			d[r]=c[j];
		}
		df();
		q();
	}
	for(int i=1;i<=b;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
