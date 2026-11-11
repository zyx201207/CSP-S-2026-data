#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	string s;
}a[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,num=0;
	string se;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].s;
		for(int j=0;j<a[i].x;j++){
			se+=a[i].s;
			sum++;
		}
	}
	int x=sum-1;
	for(int i=0;i<sum;i++){
		if(i==x||i+1==x){
			break;
		}
		if(se[i]!=se[x]){
			num++;
		}
		x--;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
