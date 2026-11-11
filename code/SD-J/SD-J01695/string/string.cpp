#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200020],b[200020],c[200020],d[200020];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,x;
	int n,mid,mid2,l,r,o=1,q=1,cnt=0;
	cin>>n;
	b[1]=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
		b[i+1]=b[i]+a[i];
	}
	if(b[n+1]%2==1) {
		mid=b[n+1]/2+1;
		for(int i=1; i<=n+1; i++) {
			if(b[i]<mid&&b[i+1]>=mid) {
				l=i,r=i+1;
			}
		}
		for(int i=1; i<=l; i++) {
			c[i]=b[i];
		}
		for(int i=r; i<=n+1; i++) {
			d[n-i+2]=b[n+1]-b[i];
			x[n-i+1]=s[i];
		}
		c[l+1]=mid-1;
		d[n-r+3]=mid-1;
		x[n+2-r]=s[l];
		while(true) {
			if(c[o]==mid-1) {
				break;
			}
			if(d[q]==mid-1) {
				break;
			}
			if(c[o]==d[q]&&c[o+1]==d[q+1]){
				if(s[o]!=x[q]) {
					cnt+=(c[o+1]-c[o]);
				}
				o++;
			}else{
			if(c[o]>=d[q]&&c[o+1]<=d[q+1]) {
				if(s[o]!=x[q]) {
					cnt+=(c[o+1]-c[o]);
				}
				o++;
			}if(c[o]<=d[q]&&c[o+1]>=d[q+1]) {
			if(s[o]!=x[q]) {
				cnt+=(d[q+1]-d[q]);
			}
			q++;
		}	if(c[o]<=d[q]&&c[o+1]<=d[q+1]&&c[o+1]>d[q]) {
				if(s[o]!=x[q]) {
					cnt+=c[o+1]-d[q];
				}
				o++;
			}if(c[o]>=d[q]&&c[o+1]>=d[q+1]&&d[q+1]>c[o]) {
			if(s[o]!=x[q]) {
				cnt+=d[q+1]-c[o];
			}
			q++;
		}
		 else {
		if(d[q+1]<=c[o]) {
			q++;
		}
		if(c[o+1]<=d[q]) {
			o++;
		}
		}
	
	}
}
	cout<<cnt;
	}if(b[n+1]%2==0) {
		mid=b[n+1]/2;
		mid2=b[n+1]/2+1;
		for(int i=1; i<=n+1; i++) {
			if(b[i]<mid&&b[i+1]>=mid2) {
				l=i,r=i+1;
			}
		}
		for(int i=1; i<=l; i++) {
			c[i]=b[i];
		}
		for(int i=r; i<=n+1; i++) {
			d[n-i+2]=b[n+1]-b[i];
			x[n-i+1]=s[i];
		}
		c[l+1]=mid;
		d[n-r+3]=mid;
		x[n+2-r]=s[l];
			while(true) {
			if(c[o]==mid) {
				break;
			}
			if(d[q]==mid) {
				break;
			}
				if(c[o]==d[q]&&c[o+1]==d[q+1]){
				if(s[o]!=x[q]) {
					cnt+=(c[o+1]-c[o]);
				}
				o++;
			}else{
			if(c[o]>=d[q]&&c[o+1]<=d[q+1]) {
				if(s[o]!=x[q]) {
					cnt+=c[o+1]-c[o];
				}
				o++;
			}if(c[o]<=d[q]&&c[o+1]>=d[q+1]) {
			if(s[o]!=x[q]) {
				cnt+=d[q+1]-d[q];
			}
			q++;
		}	if(c[o]<=d[q]&&c[o+1]<=d[q+1]&&c[o+1]>d[q]) {
				if(s[o]!=x[q]) {
					cnt+=c[o+1]-d[q];
				}
				o++;
			}if(c[o]>=d[q]&&c[o+1]>=d[q+1]&&d[q+1]>c[o]) {
			if(s[o]!=x[q]) {
				cnt+=d[q+1]-c[o];
			}
			q++;
		}
		 else {
		if(d[q+1]<=c[o]) {
			q++;
		}
		if(c[o+1]<=d[q]) {
			o++;
		}
		}
	
	}
}
	cout<<cnt<<endl;
	}
	return 0;
}
