#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,min,temp=0,mix=0,tempa,mina;
	int a[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			if(a[i]>a[j] || a[i]==a[j]){
				temp+=a[i]-a[j];
				mix++;
			}
			else{
				continue;
			}
			if(temp>m){
			temp=0;
			mix=0;
			break;
	}
		else{
			tempa=m-temp;
		}
		if(i==0){
			min=tempa;
			mina=mix;
			mix=0;
			temp=0;
		}
		else{
			
			if(tempa<=min && mix>mina){
				mina=mix;
				min=tempa;
				mix=0;
				temp=0;
				break;
			}

		}
	}
	
		
}
	cout<<mina;
	return 0;
} 



