#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[2000005],b,cnt=0,sum=0;
	char x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>x;
		cnt++; 
		for(int j=i;j<i+b;j++){
			a[j]=x;
		}
	}
	int num=cnt;
	for(int i=1;i<=cnt;i++){
		if(a[i]!=a[num]){
			sum++;
		}
		num--;
		if(i=num){
			break;
		}
	}
	cout<<sum; 
	return 0;
}
