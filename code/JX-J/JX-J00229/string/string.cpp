#include<bits/stdc++.h>
using namespace std;
char c[100005];
long long b[100005],a[100005];
int n;
char s(int x){
	for(int i=1;i<=n;i++){
		if(x+1<=b[i]){
			//cout<<b[1]<<' '<<i<<' '<<c[i-1]<<endl;
			return c[i-1];
			}
		}
	return 0;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
	}long long sum=b[n];long long j=0;
	for(long long i=b[n]-1;i>=0;i--){
		if(s(i)==s(j))sum--;
		j++;
		//cout<<i<<' '<<j<<endl<<s(i)<<' '<<s(j)<<endl<<sum<<endl;
	}
	cout<<sum/2<<endl;
	return 0;
}
