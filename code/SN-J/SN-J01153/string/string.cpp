#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	long long int a[100001],d[100001],n=0,m=0;
	char b[100001],c[100001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			c[j+i-1+n]=b[i+j-1];
			if(c[j+i-1+n]=='a') d[j+i+n]=1;
			if(c[j+i-1+n]=='b') d[j+i+n]=2;
			if(c[j+i-1+n]=='c') d[j+i+n]=3;
			if(c[j+i-1+n]=='d') d[j+i+n]=4;
			if(c[j+i-1+n]=='e') d[j+i+n]=5;
			if(c[j+i-1+n]=='f') d[j+i+n]=6;
			if(c[j+i-1+n]=='g') d[j+i+n]=7;
			if(c[j+i-1+n]=='h') d[j+i+n]=8;
			if(c[j+i-1+n]=='i') d[j+i+n]=9;
			if(c[j+i-1+n]=='j') d[j+i+n]=10;
			if(c[j+i-1+n]=='k') d[j+i+n]=11;
			if(c[j+i-1+n]=='l') d[j+i+n]=12;
			if(c[j+i-1+n]=='m') d[j+i+n]=13;
			if(c[j+i-1+n]=='n') d[j+i+n]=14;
			if(c[j+i-1+n]=='o') d[j+i+n]=15;
			if(c[j+i-1+n]=='p') d[j+i+n]=16;
			if(c[j+i-1+n]=='q') d[j+i+n]=17;
			if(c[j+i-1+n]=='r') d[j+i+n]=18;
			if(c[j+i-1+n]=='s') d[j+i+n]=19;
			if(c[j+i-1+n]=='t') d[j+i+n]=20;
			if(c[j+i-1+n]=='u') d[j+i+n]=21;
			if(c[j+i-1+n]=='v') d[j+i+n]=22;
			if(c[j+i-1+n]=='w') d[j+i+n]=23;
			if(c[j+i-1+n]=='x') d[j+i+n]=24;
			if(c[j+i-1+n]=='y') d[j+i+n]=25;
			if(c[j+i-1+n]=='z') d[j+i+n]=26;
		}
		n+=a[i];
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
		    if(d[i]==d[n-i+1]){
		    	continue;
			}
			else{
				m++;
			}
	    }
	}
	if(n%2==1){
		for(int i=1;i<=(n+1)/2-1;i++){
		    if(d[i]==d[n-i+1]){
		    	continue;
			}
			else{
				m++;
			}
	    }
	}
	m-=1;
	cout<<m;
	return 0;
} 
