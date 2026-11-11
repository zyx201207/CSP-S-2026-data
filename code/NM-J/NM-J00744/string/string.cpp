#include<bits/stdc++.h>
using namespace std;
const long long N=1e7;
long long a[N],b[N],c[N],n,cnt,ans;
int sum;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,k=1;i<=n;i++){
		cin>>a[i]>>s[i];
		cnt+=a[i];
		if(s[i]=='a'){
			for(int j=1;j<=a[i];j++){
				b[k]=1;k++;
			}
		}
		else if(s[i]=='b'){
			for(int j=1;j<=a[i];j++){
				b[k]=2;k++;
			}
		}
		else if(s[i]=='c'){
			for(int j=1;j<=a[i];j++){
				b[k]=3;k++;
			}
		}
	}
	sum=cnt/2;
	for(int i=cnt,j=1;i>=sum&&j<=sum;i--,j++){
		if(b[j]!=b[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
