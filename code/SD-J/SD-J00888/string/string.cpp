#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];unsigned long long x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c;bool f=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		if(i==1) c=s[1];
		if(c!=s[i]) f=1;
	} 
	if(f==1){
		cout<<"0";
		return 0;
	}
	unsigned long long sum=0;
	int l=1,r=n;
	while(l<r){
		if(s[l]==s[r]&&x[l]==x[r]){
			l++,r--;
		}else if(s[l]==s[r]&&x[l]!=x[r]){
			if(x[l]>x[r]){
				x[r-1]-=(x[l]-x[r]);
				sum+=(x[l]-x[r]);
				x[r]=x[l];
				r--;
				l++;
			}else{
				x[l+1]-=(x[r]-x[l]);
				sum+=(x[r]-x[l]);
				x[l]=x[r];
				r--,l++;
			}
		}else{
			if(x[l]>x[r]){
				sum+=x[r];
				s[r]=s[l];
				x[r-1]-=(x[l]-x[r]);
				sum+=(x[l]-x[r]);
				x[r]=x[l];
				l++;
				r--;
			}else if(x[r]>x[l]){
				sum+=x[l];
				s[l]=s[r];
				x[l+1]-=(x[r]-x[l]);
				sum+=(x[r]-x[l]);
				x[l]=x[r];
				l++;
				r--;
			}else{
				sum+=x[l];
				s[l]=s[r];
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
