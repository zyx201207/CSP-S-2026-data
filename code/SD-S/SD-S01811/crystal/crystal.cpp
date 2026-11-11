#include<bits/stdc++.h>
using namespace std;
int n,f,g,ans=1;
long long m,a[500010],qwe;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qwe+=a[i];
	}
	sort(a+1,a+n+1);
 	qwe/=n;
	for(int i=1;i<=n;i++){
		int qqq1=abs(a[i]-qwe),qqq2=abs(a[f]-qwe);
		if(qqq1<=qqq2){
			f=i;
		}
		if(qqq1<qqq2){
			g=i;
		}
	}
	if(a[g]-a[g-1]<=a[f+1]-a[f] || f==n){
		int h=f-1;
		if(a[f]-a[h]<m){
			m-=(a[f]-a[h]);
			ans++;
		}
		while(m>0 && h>=1){
			ans++; 
			h--;
			m-=(a[f]-a[h]);
		}
		h=f+1;
		while(m>0 && h<=n){
			ans++;
			h++; 
			m-=(a[h]-a[f]);
		}
		if(m<0) ans--;
	}
	else{
		int h=f+1;
		if(a[h]-a[f]<m){
			m-=(a[h]-a[f]);
			ans++;
		}
		while(m>0 && h<=n){
			ans++; 
			h++;
			m-=(a[h]-a[f]);
		}
		h=f+1;
		while(m>0 && h>=1){
			ans++;
			h--; 
			m-=(a[f]-a[h]);
		}
		if(m<0) ans--;
	}
	cout<<ans;
	return 0;
} 
/*
7 9
1 4 4 5 6 7 8

4
*/
