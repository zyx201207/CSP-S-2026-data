#include<bits/stdc++.h>
using namespace std;
 long long n,a[200005],x=0,l=0,ans,zm[27],zs;
 string s,z;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	char sr;
	
	cin>>n;
	for(long long i=0;i<=n-1;i++){
		cin>>a[i];
		cin>>sr;
		zs+=a[i];
		for(long long j=0;j<=a[i];j++){
			s[x]=sr;
			x++;	
		}
	}
	x=0;
	for(long long i=zs;i>=0;i--){
		z[x]=s[i];
		x++;
	}

	
	for(long long i=0;i<=zs;i++){
		if(s[i]==z[i]){
			z[i]='0';
		}	
	}
	for(long long i=1;i<=zs;i++){
		if(z[i]!='0'){
			zm[z[i]-'a'+1]++;
		}else{
			l++;
		
		}
	}
	for(long long i=1;i<=27;i++){
		if(zm[i]>zm[i+1]){
			swap(zm[i],zm[i+1]);
		}
	}
	cout<<zs-zm[26]-l;
return 0;
}
