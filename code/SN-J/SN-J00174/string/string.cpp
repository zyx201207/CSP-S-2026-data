//Ô­è÷Ðù 440514201308033019 SN-J00174
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,half,r=n;
	int i=1;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				l++,r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r]){
				sum+=a[r];
				l++,r--;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
} 
