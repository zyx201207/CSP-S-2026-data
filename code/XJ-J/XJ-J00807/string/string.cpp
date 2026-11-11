#include<bits/stdc++.h>
using namespace std;
long long a[10000001],b,e,f,d,g,h,k,n,m,sum,cnt;
string c[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	e=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]!=1){
			e=0;
		}
		cnt+=a[i];
	}
	for(int i=1;i<=n;i++){
		k+=a[i];
		if(k>=cnt/2){
			m=i;
			h=a[i];
			h-=(k-cnt/2);
			a[i]-=h*2;
			cnt-=h*2;
			if(cnt%2==1){
				f=1;
			}
			break;
		}
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
		}else{
			cout<<n/2-min(a[1],a[2]);
		}
	}else if(e==1){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]){
				sum++;
			}
		}
		cout<<sum;
	}else{
		int l=1;
		int r=n;
		while(l<r){
			if(c[l]==c[r]){
				if(a[l]>a[r]){
					a[l]-=a[r];
					sum+=a[r];
					r--;
				}else if(a[l]<a[r]){
					a[r]-=a[l];
					sum+=a[l];
					l++;
				}else{
					l++;
					r--;
					sum+=a[l];
				}
			}else{
				if(a[l]>a[r]){
					a[l]-=a[r];
					r--;
				}else if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
				}else{
					l++;
					r--;
				}
			}
		}
		cout<<sum;
	}
	return 0;
}