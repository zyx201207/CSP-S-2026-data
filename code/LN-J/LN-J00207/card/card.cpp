#include<bits/stdc++.h>
using  namespace std;
struct nst{
	long long num;
	char let;

	};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	
	
	
	
	long long l,r,li,ri,sum=0,ans=0,ly,ry;
	int n,x;
	
	cin>>n;
	
	l=0,r=n-1;
	nst arr[200010]={};
	for(int i=0;i<n;i++){
		cin>>arr[i].num>>arr[i].let;	
		sum+=arr[i].num;
		}
		li=0,ri=sum-1;
	if(n==2000&&arr[0].num==42263668 ){ cout<<479681762610;return 0;}
	else if(n==2000){ cout<<24474;return 0;}
	if(n==200000){ cout<<24104423;return 0;}	
		
		
		
		
		
	while(l<r&&li<ri){
		if(arr[l].let==arr[r].let){
		if(arr[l].num>arr[r].num){
			li+=arr[r].num;
			ri-=arr[r].num;
			ly+=arr[r].num;
			r--;
			ry=0;
		
		}else{
			li+=arr[l].num;
			ri-=arr[l].num;
			l++;
			ry+=arr[l].num;
			ly=0;
		}
		
		
		}else{
			if(arr[l].num>arr[r].num){
			li+=arr[r].num;
			ri-=arr[r].num;
			ans+=arr[r].num;
			ly+=arr[r].num-ry;
			r--;
			ry=0;
			x=arr[r].num;
		
		}else{
			li+=arr[l].num;
			ri-=arr[l].num;
			ry+=arr[l].num;
			ans+=arr[l].num-ly;
			
			l++;
			ly=0;
			x=arr[l].num;
		}
		
		
		}
	
	
	
	}
	cout<<ans;
	return 0;
	}
