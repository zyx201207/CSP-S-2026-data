#include<bits/stdc++.h>
using namespace std;

long long n,a[200010],j6,j55,jr,c7;
string j5,j7;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>j7;
		c7=a[i];
		while(c7>0){
			if(c7%2==1){
				j5+=j7;
			}
			c7/=2;
			j7=j7+j7;
		}
		/*for(int j=0;j<a[i];j++){
			j5+=j7;
		}*/
	}
	for(int i=0;i<n;i++){
		j6+=a[i];
	}
	if(j6%2==1){
	j55=(j6-1)/2;
	for(int i=0;i<j55;i++){
		if(j5[i]!=j5[j6-1-i]){
			jr++;
		}
	}
	}
	if(j6%2==0){
		j55=(j6+1)/2;
		
		for(int i=j6-1;i>=j55;i--){
		if(j5[i]!=j5[j6-1-i]){
			jr++;
		}
	}
	}
	cout<<jr;
	return 0;
	
}
