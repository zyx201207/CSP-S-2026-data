#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
int a[maxn];
char b[maxn],c[maxn*500];
long long sum=0,num=0;
long long l[maxn];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=sum-a[i]+1;j<=sum;j++){
			c[j]=b[i];
		}
	} 
	num=sum/2;
	for(int i=1;i<=num;i++){
		if(c[i]==c[i+num]){
			continue;
		}else{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

