#include<bits/stdc++.h>
using namespace std;
long long a[200001],len,minn;
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,b,d,cf=1;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>b>>d;
    	len+=b;
    	if(d==c[i-cf]){
    		cf++;
    		a[i-cf]+=b;
		}
		cf=1;
	}
	len/=2;
	char s1;
	int cd1,cd2;
	for(int i=1;i<=n;i++){
		if(len>a[i]) len-=a[i];
		else{
			s1=c[i];
			cd1=i;
			cd2=n-i;
		}	
	}
	long long sy,cl,j=0,k=0;
	for(int i=1;i<=len;i++){
		if(c[i+k]!=c[n-i+1]+j){
			if(a[i+k]>a[n-i+1+j]) minn+=a[n-i+1];
			a[i+k]-=a[n-i+1+j];
		}else{
			minn+=a[i+k];
			a[n-i+1+j]-=a[i+k];	
		}
		if(a[i+k]!=0||a[n-i+1+j]!=0){
			if(a[i+k]!=0) j++;
			if(a[n-i+1+j]!=0) k++;
			if(a[n-i+1+j]>len) j--;
			if(a[i-k]>len) k--;
		}
	}
	cout<<minn;
	return 0;
}
