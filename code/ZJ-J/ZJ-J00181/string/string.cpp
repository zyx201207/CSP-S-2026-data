#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct id{
	char zi;
	long long ge;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char cur;
	long long sum=0;
	int it=0;
	for(int i=1;i<=n;i++){
		long long k;
		char c;
		cin>>k>>c;
		if(i==1) cur=c;
		if(c==cur) sum+=k;
		else{
			it++;
			a[it].zi=cur;
			a[it].ge=sum;
			cur=c;
			sum=k;
		}
	}
	it++;
	a[it]={cur,sum};
	int l=1,r=it;
	while(l<=r){
		if(a[l].zi==a[r].zi){
			if(a[l].ge>a[r].ge){
				a[l].ge-=a[r].ge;
				r--;
			}
			else if(a[l].ge==a[r].ge){
				l++;
				r--;
			}
			else{
				a[r].ge-=a[l].ge;
				l++;
			}
		}
		else{
			if(a[l].ge>a[r].ge){
				ans+=a[r].ge;
				a[l].ge-=a[r].ge;
				r--;
			}
			else if(a[l].ge==a[r].ge){
				ans+=a[l].ge;
				l++;
				r--;
			}
			else{
				ans+=a[l].ge;
				a[r].ge-=a[l].ge;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
