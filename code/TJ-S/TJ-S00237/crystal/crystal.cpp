#include<bits/stdc++.h>
using namespace std;
long long n,m,a[900010],b;
long long c,d[900010],h;
bool f=false;
long long t;
long long ss1,ss2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]<m)	f=true;
	} 
	if(f==true) {
		if(n%2==0){
			b=n/2;
			int cnt1[100010];
			int sum=1;
			for(int i=b;i>=1;i--){
				if(a[b]!=a[i]){
					cnt1[sum]=a[b]-a[i];
					sum++;
				}	
				else h++;
			}
			sort(cnt1+1,cnt1+1+b);
			t=m;
			for(int i=1;i<=sum;i++){
				if(cnt1[i]!=0){
					t-=cnt1[i];
					if(t>=0)	ss1++;
					else break;
				}
				 
			}
			int cnt2[100010];
			sum=1;
			for(int i=b;i<=n;i++){
				if(a[b]!=a[i]){
					cnt2[sum]=a[i]-a[b];
					sum++;
				}	
				else h++;
			}	
			sort(cnt2+1,cnt2+sum);
			t=m;
			for(int i=1;i<=sum-1;i++){
				if(cnt2[i]!=0){
					t-=cnt2[i];
					if(t>=0)	ss2++;
					else break;
				}
			}		
			if(ss1>ss2)	cout<<ss1+h-1;
			else	cout<<ss2+h-1;
		}
		else{
			b=n/2+1;
			int cnt1[100010];
			int sum=1;
			for(int i=b;i>=1;i--){
				if(a[b]!=a[i]){
					cnt1[sum]=a[b]-a[i];
					sum++;
				}	
				else h++;
			}
			sort(cnt1+1,cnt1+1+b);
			t=m;
			for(int i=1;i<=sum;i++){
				if(cnt1[i]!=0){
					t-=cnt1[i];
					if(t>=0)	ss1++;
					else break;
				}
				 
			}
			int cnt2[100010];
			sum=1;
			for(int i=b;i<=n;i++){
				if(a[b]!=a[i]){
					cnt2[sum]=a[i]-a[b];
					sum++;
				}	
				else h++;
			}	
			sort(cnt2+1,cnt2+1+b);
			t=m;
			for(int i=1;i<=sum-1;i++){
				if(cnt2[i]!=0){
					t-=cnt2[i];
					if(t>=0)	ss2++;
					else break;
				}
			}		
			if(ss1>ss2)	cout<<ss1+h-1;
			else	cout<<ss2+h-1;
		}	
	}
	else	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
