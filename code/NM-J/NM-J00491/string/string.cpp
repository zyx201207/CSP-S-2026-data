#include<bits/stdc++.h>
using namespace std;
int iff;
int main (){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	string a,b,c;
	string qbd;
	string hbd;
	int n,x;
	string x1;
	cin >> n;
	int gj=0,num=0;
	for(int i=0;i<n;i++){
		cin >> x >>x1;
		for(int j=0;j<x;j++){
			a[gj]=x1[0];
			gj++;
		}
		num+=x;
	}
	int gjj=gj-1;
	for(int i=0;i<num;i++){
		c[i]=a[gjj];
		gjj--;
	}
	for(int i=0;i<=num;i++){
		if(c[i]==a[i]){
			iff=0;
		}else{
			iff=1;
			break;
		}
	}
	if(iff==0){
		cout <<iff;
		return 0;
	}
	int sum=0;
	int gj3=(num/2)-1;
	for(int i=0;i<=gj3;i++){
		qbd[i]=a[i];
	}
	int gj4=gj3+1;
	if(num%2==0){
		for(int i=0;i<=gj3;i++){
			hbd[i]=a[gj4];
			gj4++;
		}
	}
	else{
		gj4++;
		for(int i=0;i<=gj3;i++){
			hbd[i]=a[gj4];
			gj4++;
		}
	}
	int gj2=num/2-1;
	for(int i=0;i<num/2;i++){
		b[i]=hbd[gj2];
		gj2--;
	}
	for(int i=0;i<=gj3;i++){
		if(qbd[i]!=b[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
