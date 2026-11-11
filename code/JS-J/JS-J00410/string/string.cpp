#include<bits/stdc++.h>
#define int  long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	string s="";
	vector<int>a(n+1);
	for(int i=0;i<n;i++){
		char c;
		cin>>a[i]>>c;
		s=s+c;
	}
	int i=0,d=s.size()-1;
	while(i<d){
		if(s[i]!=s[d]){
			sum+=min(a[i],a[d]);
			if(a[i]<a[d]){
			a[d]-=a[i];
			i++;
			}
			else if(a[i]==a[d]){
			i++;
			d--;
			}
			else{ 
			a[i]-=a[d];
			d--;
			}
		}
		else{
			if(a[i]<a[d]){
			a[d]-=a[i];
			i++;
			}
			else if(a[i]==a[d]){
			i++;
			d--;
			}
			else{ 
			a[i]-=a[d];
			d--;
			}
		}
	}
	cout<<sum;
	return 0;
}
