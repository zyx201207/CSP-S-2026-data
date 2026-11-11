#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,j=0,ans=0,r=0;
string c2;
bool b=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c1;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		while(a>=1){
			c2[j]=c;
			j++;
			a--;
		}
		if(i!=0){
			if(c1!=c){
				b=0;
			}
		}
		c1=c;
	}
	r=sum-1;
	for(int i=0;i<sum/2;i++){
		if(c2[i]!=c2[r]) ans++;
		r--;
	}
	if(b==1) cout<<0;
	else cout<<ans;
	fclose(stdin);
	fclose(stdout);
return 0;
}
