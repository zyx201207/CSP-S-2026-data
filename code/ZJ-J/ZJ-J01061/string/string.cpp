#include<bits/stdc++.h>
using namespace std;
struct stg{
	long long k;
	char l;
}osr[500200];
long long many,ans,oum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>many;
	for(int i=1;i<=many;i++){
		cin>>osr[i].k>>osr[i].l;
		oum+=osr[i].k;
	}
	if(oum%2==1){
	int num=1,sum=many,num_1=0,sum_2=0,num_2=0,sum_3=0;
	while(1){
		if(num_1==osr[num].k){
			num++;
			num_1=1;
		}
		if(num_2==osr[sum].k){
			sum++;
			sum_2=1;
		}
		if(osr[num].l!=osr[sum].l){
			ans++;
		}
		 num_1++;
		sum_2++;
		num_2++;
		sum_3++;
        if(num_2==oum/2&&sum_3==oum/2){
        	cout<<ans;
        	return 0;
		}	
	}
	
	} else{
		int num=1,sum=many,num_1=0,sum_2=0,num_2=0,sum_3=0;	
		while(1){
			if(num_1==osr[num].k){
			num++;
			num_1=1;
		}
		if(num_2==osr[sum].k){
			sum++;
			sum_2=1;
		}
		if(osr[num].l!=osr[sum].l){
			ans++;
		}
		num_1++;
		sum_2++;
		num_2++;
		sum_3++;
        if(num_2==oum/2&&sum_3==oum/2){
        	cout<<ans;
        	return 0;
		}
	}
	
	}
	cout<<ans;
	return 0;
}

