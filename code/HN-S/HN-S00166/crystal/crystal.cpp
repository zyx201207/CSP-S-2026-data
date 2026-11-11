#include<bits/stdc++.h>
using namespace std;
int n,m,len=1,maxlen=1; 
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		m-=((a[i]-a[i-1])*len);
		while(m<0){
			len--;
			m+=a[i]-a[i-len];
		}
		//cout<<m;
		len++;
		maxlen=max(len,maxlen); 
	}
	cout<<maxlen<<"\n";
} 
