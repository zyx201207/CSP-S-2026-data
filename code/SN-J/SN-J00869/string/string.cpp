#include<bits/stdc++.h>
using namespace std;
struct zfc{
	char zm;
	long long num;
} a[50005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].zm;
		len+=a[i].num;
	}
	long long l=1,r=n,cnt=0;
	while(l!=r){
		if(a[l].num>a[r].num){
			if(a[l].zm!=a[r].zm){
				cnt+=a[r].num;
				
			}
			a[l].num-=a[r].num;
			
			r--;
			
		}
		if(a[l].num<a[r].num){
			if(a[l].zm!=a[r].zm){
				cnt+=a[l].num;
				
			}
			a[r].num-=a[l].num;
			
			l++;
			
		}
		if(a[l].num==a[r].num){
			if(a[l].zm!=a[r].zm){
				cnt+=a[l].num;
				
			}
			r--;
			
			l++;
			
		}
			
	}
	cout<<cnt;

	return 0;
}



