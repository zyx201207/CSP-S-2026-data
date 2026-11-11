#include<bits/stdc++.h>
using namespace std;
/*
5
1 b
3 a
1 b
2 a
2 b
*/
/*
7
1 b
5 a
2 b
1 c
2 a
1 b
2 c
*/
/*
10
1 b
3 a
2 b
1 c
1 a 
1 b
2 c
2 a
2 b
3 c
*/
const int N=2e5+5;
int n,a[N],val[N];
char c[N];
long long ans,len,sum[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		val[i]=a[i];
		sum[i]+=sum[i-1]+a[i];
		//cout<<a[i]<<endl;
	}
	//cout<<len<<endl; 
	int j=n;
	bool lst=0;
	for(int i=1;i<j;){
		if(len-sum[i]>sum[j-1]){
			if(c[i]!=c[j]){
				ans+=val[i];
			}
			val[j]-=val[i];
			i++;
			lst=0;
			//cout<<"chosen1 ";
		}else if(len-sum[i]<sum[j-1]){
			if(c[i]!=c[j]){
				ans+=val[j];
			}
			val[i]-=val[j];
			j--;
			lst=1;
			//cout<<"chosen2 ";
		}else if(len-sum[i]==sum[j-1]){
			if(c[i]!=c[j]&&lst==1) ans+=a[j];
			if(c[i]!=c[j]&&lst==0) ans+=a[i];
			j--;
			i++;
		}
		//cout<<"ans:"<<ans<<" i:"<<i<<" j:"<<j<<endl;
	}
	cout<<ans;
	return 0;
} 
/*
6 
1000000000 a 
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b
*/
