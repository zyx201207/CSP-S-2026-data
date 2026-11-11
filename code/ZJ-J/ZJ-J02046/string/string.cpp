#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	long long sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		char c;
		cin>>k>>c;
		sum+=k;
		a[i]=k;
		b[i]=int(c-'a'+1);
	}
	long long sum1=0,l=1,r=n,L=1,R=sum;
	for(int i=1;i<=n;i++){
		if(l>r)break;
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				
				L+=a[r];
				R-=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				
				L+=a[l];
				R-=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				L+=a[l];
				R-=a[r];
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				
				L+=a[r];
				R-=a[r];
				a[l]-=a[r];
				sum1+=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				
				L+=a[l];
				R-=a[l];
				a[r]-=a[l];
				sum1+=a[l];
				l++;
			}
			else{
				L+=a[l];
				R-=a[r];
				l++;
				r--;
				sum1+=a[l];
			}
		}
	}
	cout<<sum1;
	return 0;
}                                    