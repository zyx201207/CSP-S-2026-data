#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,sum=0,diff1=0,diff2=-1,ch=0;
	string c,d;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		cin>>c;
		for(int j=1;j<=b;j++){
			d+=c;
			sum++;
			}
		}
		for(int i=2;i<=sum/2;i++){
			if(d[i]!=d[i-1]){
				diff1++;}
			}
		for(int i=sum/2+2;i<=sum;i++){
			if(d[i]!=d[i-1]){
				diff2++;
				}
			}
		if(diff1==diff2&&diff1==0){
			cout<<0;
			return 0;
			}else{
				for(int i=1;i<=sum/2;i++){
					if(d[i-1]!=d[sum-i])ch++;
					}
					
				}
		cout<<ch;
return 0;
}
