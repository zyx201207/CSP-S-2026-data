#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<long long> a(n);
	vector<char> c(n);
	int count=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n!=1){
		int tool=n;
		for(int i=0;i<tool;i++){
			if(c[i]==c[tool-i-1]){
				if(a[i]>a[tool-i-1]){
					a[i]=a[i]-a[tool-i-1];
					tool--;
					i--;
				}
				if(a[i]<a[tool-i-1]){
					a[tool-i-1]=a[tool-i-1]-a[i];
					tool++;
				}
				if(a[i]==0||a[tool-i-1]==0)	break;
			}
			if(c[i]!=c[tool-i-1]){
				if(a[i]==a[tool-i-1]&&a[i]!=0){
					count+=a[i];
				}
				if(a[i]>a[tool-i-1]){
					a[i]=a[i]-a[tool-i-1];
					count+=a[tool-i-1];
					tool--;
					i--;
				}
				if(a[i]<a[tool-i-1]){
					a[tool-i-1]=a[tool-i-1]-a[i];
					count+=a[i];
					tool++;
				}
				if(a[i]==0||a[tool-i-1]==0)	break;
			}
		}	
	}
	cout<<count;
return 0;
}
