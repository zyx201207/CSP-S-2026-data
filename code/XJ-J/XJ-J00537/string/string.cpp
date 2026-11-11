#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int long n=0;
long long m=0;
int a[1000000]={0};
char b[1000000];

bool abc(int bigan, int end){
	if(bigan == end){
		return 0;
	}
	if(a[bigan]>a[end] && a[bigan]!=0 && a[end]!=0 && int(b[bigan])!=int(b[end])){
		m=m+a[end];
		a[bigan]=a[bigan]-a[end];
		a[end]=0;
		abc(bigan,end-1);
	}
	if(a[bigan]<a[end] && a[bigan]!=0 && a[end]!=0 && int(b[bigan])!=int(b[end])){
		m=m+a[bigan];
		a[bigan]=0;
		a[end]=a[end]-a[bigan];
		abc(bigan+1,end);
	}
	if(a[bigan]==a[end] && a[bigan]!=0 && a[end]!=0 && int(b[bigan])!=int(b[end])){
		m=m+a[bigan];
		if(bigan == end-1){
			abc(bigan,end-1);
		}else{
			abc(bigan+1,end-1);
		}
	}
	if(a[bigan]!=0 && a[end]!=0 && int(b[bigan])==int(b[end])){
		if(a[bigan]>a[end]){
		a[bigan]=a[bigan]-a[end];
		a[end]=0;
		abc(bigan,end-1);
		}
		if(a[bigan]<a[end]){
		a[bigan]=0;
		a[end]=a[end]-a[bigan];
		abc(bigan+1,end);
		}
		if(a[bigan]==a[end]){
			a[bigan]=0;
			a[end]=0;
		if(bigan == end-1){
			abc(bigan,end-1);
		}else{
			abc(bigan+1,end-1);
		}
		}
	}
	
	if(a[bigan]==0){
	abc(bigan+1,end);
	}
	if(a[end]==0){
	abc(bigan,end-1);
	}
}

int main(){
	//freopen("travel.in","r",srdin);
	//freopen("travel.out","w",srdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	abc(0,n-1);
	cout << m;
	return 0;
}