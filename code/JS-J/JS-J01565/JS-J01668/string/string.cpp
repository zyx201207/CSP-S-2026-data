#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],k;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		k+=a[i];
	}
	
	long long sum=0;
	
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
//			cout<<"Y";
			if(s[l]==s[r]){
			l++;
			r--;
			continue;	
			}
			else{
				sum+=a[l];
				l++;
				r--;
			}
			continue;
		}
		if(a[l]<a[r]){
	//		cout<<"T";
			if(s[l]!=s[r]){
				sum+=a[l];
			}
	//		cout<<l<<" "<<a[l]<<" "<<r<<" "<<a[r]<<" "<<a[l]-a[r]<<" "<<sum<<endl;
			a[r]-=a[l];
			l++;
			if(a[r]==0)
			r--;
		}
		else{
	//		cout<<"Z";
			if(s[l]!=s[r]){
				sum+=a[r];
			}
	//		cout<<l<<" "<<a[l]<<" "<<r<<" "<<a[r]<<" "<<a[l]-a[r]<<" "<<sum<<endl;
			a[l]-=a[r];
			r--;
			if(a[l]==0)
			{
				l++;
			}
			
		}
	}
	cout<<sum;
	return 0;
}
