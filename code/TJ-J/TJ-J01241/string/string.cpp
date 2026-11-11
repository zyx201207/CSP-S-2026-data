#include<bits/stdc++.h>
using namespace std;
struct nd{
	long long num;
	char c;
}a[2*100000+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
  	long long t;
  	cin>>t;
  	for(int i=1;i<=t;i++){
  		cin>>a[i].num>>a[i].c;
	}
	long long i=1,j=t,sum=0;
	while(true){
		if(i>=j){
			break;
		}
		if(a[i].c!=a[j].c){
			sum+=min(a[i].num,a[j].num);
		}
		i++,j--;
	}
	if(i==j){
		sum++;
	}
	cout<<sum;
	return 0;
}
