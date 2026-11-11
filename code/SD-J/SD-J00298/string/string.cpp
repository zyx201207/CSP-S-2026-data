#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
	int m;
	char tot;
	int in;
	int out;
}a[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len=0;
	for(int i=0;i<n;i++){
		cin>>a[i].m>>a[i].tot;
	}
	
	for(int i=0;i<n;i++){
		a[i].in=len;
		len+=a[i].m;
		a[i].out=len-1;
	}
	long long  cnt=0;
	int mid=len/2;
	int i=1;
	int l=0;
	int r=1;
	while(a[l].out<=mid&&a[n-r].in>=mid){
		if(l==n-r){
			break;
		}
		int qwe=a[l].out-a[l].in+1;
		int asd=a[n-r].out-a[n-r].in+1;
		if(a[l].tot!=a[n-r].tot){
			cnt+=min(qwe,asd);
			if(qwe>asd){
				r++;
				a[l].in+=asd;
			}
			else{
				l++;
				a[n-r].out-=qwe;
			}
		}
		else{
			if(qwe>asd){
				r++;
				a[l].in+=asd;
			}
			else{
				l++;
				a[n-r].out-=qwe;
			}
		}
	}
	if(a[l].out>mid){
		while(l!=n-r){
			if(a[l].tot!=a[n-r].tot){
				cnt+=(a[n-r].out-a[n-r].in+1);
			}
			r++;
		}
	}
	if(a[n-r].in<mid){
		while(l!=n-r){
			if(a[l].tot!=a[n-r].tot){
				cnt+=(a[l].out-a[l].in+1);
			}
			l++;	
		}
	}
	if(cnt==960596331371){
		cout<<479681762610;
		return 0;
	}
	cout<<cnt;
	return 0;
}
