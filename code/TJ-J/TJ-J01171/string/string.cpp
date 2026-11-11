#include<bits/stdc++.h>
using namespace std;

long long m,n,k,sum;
int s[100001];
string h,l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n>>r;
		s[i]=n;
		sum+=n;
		l+=r;
	}	
	for(int i=l.size();i>=0;i--){
		h+=l[i];
	} 
	cout<<l<<" "<<h;
	for(int i=0;i<l.size()/2+1;i++){
		if(l[i]!=h[i]){
			k+=s[i];
		}
	}
	if(sum%2==0){
		k--;
	}
	cout<<k;
	return 0;
}
