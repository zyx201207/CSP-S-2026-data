#include<bits/stdc++.h>
using namespace std;
struct sz{
	long long int gesu;
	char zifu;
};
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long int n,num=0;
	cin>>n;
	sz a[n];
	for(long long int i=0;i<n;i++){
	    cin>>a[i].gesu>>a[i].zifu;
		num=num+a[i].gesu;
	}
	sz aqb[n],ahb[n+1];
	long long int j=0,lnum=0;
	for(j=0;j<n;j++){
		if((a[j].gesu+lnum)<=num/2)
		{
			aqb[j].gesu=a[j].gesu;
			aqb[j].zifu=a[j].zifu;
			lnum=lnum+a[j].gesu;  
		}
		else{
			if(lnum<=num/2){
				aqb[j].gesu=num/2-lnum;
				aqb[j].zifu=a[j].zifu;
				ahb[n-j-1].gesu=a[j].gesu-aqb[j].gesu;
				if(aqb[j].gesu==0)ahb[n-j-1].gesu=a[j].gesu-1;
				ahb[n-j-1].zifu=a[j].zifu;	
			}
			break;
		}
	}
	for(long long int i=0;i<n-1-j;i++){
		ahb[i].gesu=a[n-i-1].gesu;
		ahb[i].zifu=a[n-i-1].zifu;
	}
	long long int qyon=0,hong=0,ct=0;
	while(qyon!=j){
		if(aqb[qyon].gesu>ahb[hong].gesu){
			if(aqb[qyon].zifu!=ahb[hong].zifu)ct=ct+ahb[hong].gesu;
			aqb[qyon].gesu=aqb[qyon].gesu-ahb[hong].gesu;
			hong++;
		}
		if(aqb[qyon].gesu<ahb[hong].gesu){
			if(aqb[qyon].zifu!=ahb[hong].zifu)ct=ct+aqb[qyon].gesu;
			ahb[hong].gesu=ahb[hong].gesu-aqb[qyon].gesu;
			qyon++;
		}
		if(aqb[qyon].gesu==ahb[hong].gesu){
			if(aqb[qyon].zifu!=ahb[hong].zifu)ct=ct+ahb[hong].gesu;
			hong++;
			qyon++;
		}
	}
	cout<<ct;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
