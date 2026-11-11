#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	int n;
}a[400001];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n1;
	cin>>n1;
	for(int i=1;i<=n1;i++){
		cin>>a[i].n>>a[i].c;
	}
	int l=1,r=n1;
	while(l<r){
		if(a[l].n<a[r].n){
			if(a[l].c==a[r].c){
				a[r].n-=a[l].n;
				l++;
			}else{
				sum+=a[l].n;
				a[r].n-=a[l].n;
				l++;	
			}
		}else{
			if(a[l].c==a[r].c){
				a[l].n-=a[r].n;
				r--;
			}else{
				sum+=a[r].n;
				a[l].n-=a[r].n;
				r--;	
			}
		}
	}
	cout<<sum;
	return 0;
}

