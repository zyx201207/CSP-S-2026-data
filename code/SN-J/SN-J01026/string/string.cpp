 #include<bits/stdc++.h>
using namespace std;
long long n,a[100000001];
string c;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0,x=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		cin>>c[cnt];
		for(int j=x;j<=cnt;j++){
			c[j]==c[cnt];
		}
		x=cnt+1;
	}
	long long sum=0;
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[cnt-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
