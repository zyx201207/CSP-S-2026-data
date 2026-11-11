#include<bits/stdc++.h> 
using namespace std;
struct node{
	int cnt;
	char c;
}a[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n=0;
	long long ccb=0,ct=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].cnt>>a[i].c;
		ct+=a[i].cnt;
	}
	int cf=0,ip=0;
	while (cf<=ct/2){
		cf+=a[ip].cnt;
		ip++;
	}
	ip--;
	int k=1;
	for (int i=0;i<=ip;i++){
		if (a[i].c!=a[n-k-i].c){
			if (a[i].cnt==a[n-k-i].cnt){
				ccb+=a[i].cnt;
			}
			else {
				ccb+=max(a[i].cnt,a[n-k-i].cnt)-min(a[i].cnt,a[n-k-i].cnt);
				if (a[i].cnt>a[n-k-i].cnt){
				a[i].cnt=a[i].cnt-a[n-k-i].cnt;
				i--;
				k++; 
				}
				else {
				a[n-k-i].cnt=a[n-k-i].cnt-a[i].cnt;
				k--;	
				}
			}
		}
		else{
			continue;
		}
	}
	cout<<ccb;
	return 0;
}
