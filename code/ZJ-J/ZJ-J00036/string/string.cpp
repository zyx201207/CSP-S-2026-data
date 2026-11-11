#include<bits/stdc++.h>
using namespace std;
long long a[200005],l,r,nl,nr,s;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	l=1,r=n;
	nl=a[1],nr=a[n];
	while(l<r){
		if(nl>nr){
			nl-=nr;
			if(b[l]!=b[r]){
				s+=nr;
			}
			r--;
			nr=a[r];
		}
		else if(nl<nr){
			nr-=nl;
			if(b[l]!=b[r]){
				s+=nl;
			}
			l++;
			nl=a[l];
		}
		else{
			if(b[l]!=b[r]){
				s+=nl;
			}
			l++;
			nl=a[l];
			r--;
			nr=a[r];
		}
	}
	cout<<s;
	return 0;
}
