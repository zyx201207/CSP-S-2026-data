#include<bits/stdc++.h>
using namespace std;
int n,l,r;
string b[100005];
long long al,a[100005],ch=0,mid;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		al+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	l=1;
	r=n;
	mid=2/n;
	while(l<=r){
		if(b[l]!=b[r]){
			long long z;
			z=min(a[l],a[r]);
			ch+=z;
			if(a[l]>a[r]){
				r-=1;
				a[l]-=z;
			}
			else if(a[l]<a[r]){
				l+=1;
				a[r]-=z;
			}
			else if(a[l]==a[r]){
				l+=1;
				r-=1;
			}
		}
		else if(b[l]==b[r]){
			long long y;
			y=min(a[l],a[r]);
			if(a[l]>a[r]){
				r-=1;
				a[l]-=y;
			}
			else if(a[l]<a[r]){
				l+=1;
				a[r]-=y;
			}
			else if(a[l]==a[r]){
				l+=1;
				r-=1;
			}
		}
	}
	cout<<ch;
	return 0;
}
