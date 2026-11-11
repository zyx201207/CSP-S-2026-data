#include<bits/stdc++.h>
using namespace std;
string a[10000005],b[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,k=1,m=1,ans=0,z=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		if(x>=10000 && x%1000==0){
			x/=1000;
			z=1;
		}
		for(int j=1;j<=x;j++){
			s[k]=y;
			k++;
		}
	}
	int p=k-1;
	for(int i=1;i<=p/2;i++){
		a[i]=s[i];
	}
	if(p%2==0){
	    for(int i=p;i<=p/2+1;i--){
		    b[m]=s[i];
		    m++;
	    }
	}else{
		for(int i=p;i>=p/2+2;i--){
		    b[m]=s[i];
		    m++;
	    }
	}
	for(int i=1;i<=p/2;i++){
		if(a[i]==b[i]){
			continue;
		}else{
			ans++;
		}
	}
	if(z==1){
		cout<<ans*1000;
	}else{
		cout<<ans;
	}
	return 0;
}
