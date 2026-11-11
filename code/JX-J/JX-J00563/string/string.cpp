#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=0;
	for(int i=0;i<n;i++){
		long long s;
		char x;
		scanf("%lld %c",&s,&x);
		if(x==c[l]){
			a[l]+=s;
		}
		else{
			l++;
			c[l]=x;
			a[l]=s;
		}
	}
	if(l==1){
		cout<<"0";
		return 0;
	}
	else{
		int r=0;
		while(r<l){
			long long mx;
			int num;
			if(a[r]<a[l]){
				mx=a[r];
				num=r;
			}
			else{
				mx=a[l];
				num=l;
			}
			if(c[r]==c[l]){
				if(l==num){
					l--;
					a[r]-=mx;
				}
				else{
					r++;
					a[l]-=mx;
				}
			}
			else{
				sum+=mx;
				if(l==num){
					l--;
					a[r]-=mx;
				}
				else{
					r++;
					a[l]-=mx;
				}
			}
			if(a[l]==0){
				l--;
			}
			if(a[r]==0){
				r++;
			}
		}
	}
	cout<<sum;
	return 0;
}
