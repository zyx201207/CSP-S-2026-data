#include<bits/stdc++.h>
const int N=5e5+1;
using namespace std;
#define ll long long

int i=0,r[N]={};


signed main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	int n;
	ll m;
    cin >> n >> m;
	long a[N];
	for (int i = 1;i <= n;i++) cin >> a[i];
	a[0]=-1;
	int b[N]; 
	int sum=0;
	int aa=0;
	//
//	int x[N]={};
	int sss=0;
	//
	int qw=0;
	
	if (m==0){
    	sort(a+1,a+1+n);
		for(i = n;i >= 1;i--){
			r[i]=0;
		    if(a[i]==a[i-1]) {
		    	while(a[i]==a[i-r[i]]) { 
		    		r[i]++;
				}
			}
		}
    	sort(r+1,r+1+n);
    	cout << r[n];
		return 0;
	}
	else if (m==1){
		sss=1;
    	sort(a+1,a+1+n);
		for(i = n;i >= 1;i--){
			r[i]=0;
		    if(a[i]==a[i-1]) {
		    	while(a[i]==a[i-r[i]]) {
		    		r[i]++;
				}
			}
		}
    	sort(r+1,r+1+n);//
    	for(i = n;i >= 1;i--){
			x[i]=0;
		    while(a[i]==a[i-x[i]]) {
		    	x[i]++;
			}
			if(x[i]==r[n]){
				if(i>sss&&a[i-1]==a[i]-sss)
				{
					cout << r[n]+sss;
				}
				else
				{
					cout << r[n];
				}
				return 0;
			}
		}
		return 0;
	}
	else if (m==2){
		sss=2;
    	sort(a+1,a+1+n);
		for(i = n;i >= 1;i--){
			r[i]=0;
		    if(a[i]==a[i-1]) {
		    	while(a[i]==a[i-r[i]]) {
		    		r[i]++;
				}
			}
		}
    	sort(r+1,r+1+n);//
    	for(i = n;i >= 1;i--){
			x[i]=0;
		    while(a[i]==a[i-x[i]]) {
		    	x[i]++;
			}
			if(x[i]==r[n]){
				if(i>sss&&a[i-sss]==a[i-1]&&a[i-sss]==a[i]-1)
				{
					cout << r[n]+sss;
				}
				else if(a[i-1]==a[i]-1)
				{
					cout << r[n]+1;
				}
				else
				{
					cout << r[n];
				}
				return 0;
			}
		}
		return 0;
	}///|///|///
	else{
		int x[N][N],aaa=0,bbb=0;
		double tr=0;
		ll mm=m;
		int mn = n;
		int mmax_=0;
		
		while(mm==0){
			sss++;
    		sort(a+1,a+1+n);
			for(i = n;i >= 1;i--){
				r[i]=0;
			    if(a[i]==a[i-1]) {
			    	while(a[i]==a[i-r[i]]) {
			    		r[i]++;
					}
				}
			}
			int x[N];
    		sort(r+1,r+1+n);//
    		for(i = n;i >= 1;i--){
				x[i]=0;
			    while(a[i]==a[i-x[i]]) {
			    	x[i]++;
				}
				if(x[i]==r[n]){
					if(i>sss&&a[i-sss]==a[i-1]&&a[i-sss]==a[i]-1)
					{
						mmax_=r[n]+sss;
					}
					else if(a[i-1]==a[i]-1)
					{
						mmax_=r[n]+1;
					}
					else
					{
						mmax_=r[n];
					}
					cout << mmax_;
					return 0;
				}
			}
		}
		
		
// 	   	sort(r+1,r+1+n);
//			tr/=2.0;
//			tr/=n;
//			for(i=1;i <= n;i++) {
//				x[aaa][i]=r[mn--];
//			}
//			aaa++;
//		
//		
//		}
//		for(i = n;i >= 1;i--){
//			r[i]=0;	
//		    if(a[i]==a[i-1]) {
//		    	while(a[i]==a[i-r[i]]) {
//		    		r[i]++;
//				}
//			}
//		}
//		sort(r+1,r+1+n);
//		cout << r[n];
	}
	
	
	
	
	
	
	
	
	return 0;
} 