#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[500005],b,ji,cu;
int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		s[i-1]=a[i]-a[i-1];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b+=s[j];
		    ji++;
		    if(b+s[j]>m){
		    	cu=max(ji,cu);
		    	ji=0;
		    	b=0;
			    //break;
			    j=n+1;
		    }
		}
	}
	cout<<cu;
	freopen("crystal.out","w",stdout);
	return 0;
}