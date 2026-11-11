#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct repeat{
	ll l1;
	char l2;
}a[200505];
ll sum,num,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>a[i].l1>>a[i].l2;
		sum+=a[i].l1;
	}	
	ll hja=sum/2;
	sum/=2;
	ll x=a[1].l1,y=a[n].l1,k1=0,k2=0;
	num=a[1].l1,ans=a[n].l1;
	while (x<=hja&&y<=hja){
		if(num>=ans){
			if(a[1+k1].l2==a[n-k2].l2){
				sum-=ans;
			}	
			num-=ans;
			k2++;
			ans=a[n-k2].l1;
			y+=ans;
		}
		else{
			if(a[1+k1].l2==a[n-k2].l2){
				sum-=num;
			}	
			ans-=num;
			k1++;
			num=a[1+k1].l1;
			x+=num;
		}
	}
	if(num>=ans&&num!=0&&ans!=0){
		if(a[1+k1].l2==a[n-k2].l2){
			sum-=ans;
		}
		sum-=((num-ans)/2);
	}
	else if(ans>num&&num!=0&&ans!=0){
		if(a[1+k1].l2==a[n-k2].l2){
			sum-=num;
		}
		sum-=((ans-num)/2);		
	}
	cout<<sum<<endl;
	return 0;
}

