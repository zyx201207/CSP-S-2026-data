#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5*2+5;
long long a[N];
bool flag=0;
long long flag1;
char c[N];
string b;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(i==1) flag1=a[i];
		else if(flag1!=a[i]) flag=1;
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			b+=c[i];
		}
		long long ans=0;
		long long i=0,j=b.size()-1;
		while(i<=b.size()/2-1){
		
			if(b[i]!=b[j]) ans++;
			i++;
			j--;
		}	
		cout<<ans*flag1;
		return 0;	
	}
	for(int i=1;i<=n;i++){
		int z=a[i];
		while(z--) b+=c[i];
	}
	//cout<<b;
	long long ans=0;
	int i=0,j=sum-1;
	while(i<=sum/2-1){
		
		if(b[i]!=b[j]) ans++;
		i++;
		j--;
	}
	cout<<ans;
}
