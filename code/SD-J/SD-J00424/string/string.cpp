#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	long long z=0;
	for(int i=0;i<n;i++){
		cin>>a[i];z+=a[i];char c;cin>>c;s+=c;
	}
	long long r=0,l=n-1,x=z;z/=2;
	while(l>r){
		if(s[r]!=s[l]){
			if(a[r]>a[l]){a[r]-=a[l];a[l]=0;l--;}
			else if(a[r]<a[l]){a[l]-=a[r];a[r]=0;r++;}
			else{a[r]=0;a[l]=0;r++;l--;}
			continue;
		}
		if(a[l]>a[r]){
			z-=a[r];a[l]-=a[r];a[r]=0;
			r++;
		}else if(a[l]<a[r]){
			z-=a[l];a[r]-=a[l];a[l]=0;
			l--;
		}else{
			z-=a[l];a[l]=0;a[r]=0;
			l--;r++;
		}
	}
	if(a[l]!=0||a[r]!=0) z-=max(a[l],a[r])/2;
//	if(x%2!=0&&(a[l]!=0||a[r]!=0)){
//		long long x1=a[x/2+1],x2=max(a[l],a[r]),d1=x/2+1,d2;
//		if(a[l]!=0) d2=l;else d2=r;
//		if(d1==d2){cout<<z;return 0;}
//		else{z-=max(x1,x2)-min(x1,x2);}
//	}
	cout<<z;
	return 0;
}
