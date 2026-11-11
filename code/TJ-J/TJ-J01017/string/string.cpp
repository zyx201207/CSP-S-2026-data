#include<bits/stdc++.h>
using namespace std;
string arr,a,b;
struct xx{
	long long sl;
	char zm;
}mm[1234567];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,jl=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mm[i].sl>>mm[i].zm;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=mm[i].sl;j++){
			arr=arr+mm[i].zm;
		}
	}
	if(arr.size()%2!=0){
		jl=arr.size()/2;
		a=arr.substr(0,jl-1);
		b=arr.substr(jl+1,jl*2+1);
	}else{
		jl=arr.size()/2;
		a=arr.substr(0,jl);
		b=arr.substr(jl,jl*2);
	}
	long long ans=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
