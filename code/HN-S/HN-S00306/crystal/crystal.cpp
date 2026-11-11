#include<bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
	preopen("crystal.in","r","stdin");
	preopen("crystal.out","w","stdout");
	cin.tie(0);cout.tie(0);
	int a1,b1;
	cin>>a1>>b1;
	for(int i=0;i<a1;i++)cin>>a[i];
	sort(a,a+a1);
	long long max1=1;
	while(b1--){
		long long max2=1,chazhi=1000000000000,xiabiao=0;
		for(int i=0;i<a1-1;i++){
			if(a[i]==a[i+1]){
				max2++;
				if(max2>max1)max1=max2;
			}
			else {
				max2==1;
				if(a[i+1]-a[i]<chazhi){
					chazhi=a[i+1]-a[i];
					xiabiao=i;
				}
			}
		}
		a[xiabiao]++;
	}
	long long max2=1;
	for(int i=0;i<a1-1;i++){
		if(a[i]==a[i+1]){
			max2++;
			if(max2>max1)max1=max2;
		}
		else max2==1;
	}
	cout<<max1;
} 
