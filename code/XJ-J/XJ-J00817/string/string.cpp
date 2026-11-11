#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,sum=0;char s;
	cin>>n;
	vector<int>a(n+1,0);
	vector<int>b(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		sum+=x;
		a[i]=sum;
		b[i]=s;
	}
	int l1=sum;
	vector<int>left(200,0);
	vector<int>right(200,0);
	if(sum%2==0){
		sum/=2;
		for(int i=1;i<=n;i++){
			if(a[i]<=sum){
				left[b[i]]+=a[i]-a[i-1];
			}
			else{
				if(a[i-1]>=sum){
					right[b[i]]+=a[i]-a[i-1];
				}
				else{
					left[b[i]]+=sum-a[i-1];
					right[b[i]]+=a[i]-sum;
				}	
			}
		}
	}
	else {
		sum=sum/2+1;
		for(int i=1;i<=n;i++){
			if(a[i]<sum){
				left[b[i]]+=a[i]-a[i-1];
			}
			else if(a[i]==sum)left[b[i]]+=sum-1;
			else{
				if(a[i-1]==sum){
					right[b[i]]+=a[i]-sum;
				}
				else if(a[i-1]<sum){
					left[b[i]]+=sum-a[i-1]-1;
					right[b[i]]+=a[i]-sum;
				}
				else{
					right[b[i]]+=a[i]-a[i-1];
				}	
			}
		}
	}
	int ml=-9999,mr=-9999,l,r;
	for(int i=0;i<=200;i++){
		if(left[i]>ml){
			ml=left[i];
			l=i;
		}
	}
	for(int i=0;i<=200;i++){
		if(right[i]>mr){
			mr=right[i];
			r=i;
		}
	}
	if(ml>mr){
		cout<<l1/2*2-ml;
	}
	else if(ml==mr&&l==r)cout<<l1/2*2-2*ml;
	else cout<<l1/2*2-mr;
}