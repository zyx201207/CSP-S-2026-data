#include<bits/stdc++.h>
using namespace std;
long long s;
int a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
}
    if(n==2){
    	if(b[1]==b[2]){
    		cout<<'0';
    		return 0;
		}
		else if(b[1]!=b[2]&&a[1]==a[2]){
			cout<<a[1];
			return 0;
		}
		else{
			cout<<min(a[1],a[2]);
			return 0;
		}
	}
	int r=1,l=n;
	while(r<l){
		if(a[l]==a[r]&&b[l]!=b[r]){
			s+=a[l];
		}
		else if(a[l]>a[r]&&b[l]!=b[r]){
			s+=a[l];
			a[r+1]-=a[l]-a[r];
		}
		else if(a[l]<a[r]&&b[l]!=b[r]){
			s+=a[r];
			a[l-1]-=a[r]-a[l];
		}
		else if(a[l]<a[r]&&b[l]==b[r]){
			s+=a[r]-a[l];
			a[l-1]-=a[r]-a[l];
		}
		else if(a[l]>a[r]&&b[l]!=b[r]){
			s+=a[l]-a[r];
			a[r+1]-=a[l]-a[r];
		}
		r++;
		l--;
	}
	cout<<s;
	return 0;
} 
