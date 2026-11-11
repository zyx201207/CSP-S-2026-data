#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}a[500000];
int n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		a[i].num=x;
		a[i].c=y;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].c!=a[j].c){
			if(a[i].num>a[j].num){
				a[i].num=a[i].num-a[j].num;
				sum=sum+a[j].num;
				j--;
			}else if(a[i].num<a[j].num){
				a[j].num=a[j].num-a[i].num;
				sum=sum+a[i].num;
				i++;
			}else{
				sum=sum+a[j].num;
				i++;
				j--;
			}
		}
		if(a[i].c==a[j].c){
			if(a[i].num>a[j].num){
				a[i].num=a[i].num-a[j].num;
				j--;
			}else if(a[i].num<a[j].num){
				a[j].num=a[j].num-a[i].num;
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<sum;
}
