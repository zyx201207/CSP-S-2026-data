#include<algorithm>
#include<iostream>
using namespace std;
int n,ans;
long long m;
long long a[500009],pre[500009];
bool cmp(long long x,long long y){
	return x>y;
}
string check(int i,int j){
	if(i<=j)return "YES";
	return "NO";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int i=1,j=1;
	long long sum=0;
	int mxlen=0;
	while(i<=j&&j<=n){
		int len=j-i+1;
		mxlen=max(mxlen,len);
//		cout<<i<<' '<<j<<"  "<<sum<<' '<<'\n';
		j++;
		if(j>n)break;
		sum+=(a[j]-a[j-1])*(j-i);
		if(sum>m){
			//cout<<i<<' '<<j<<"  "<<sum<<' '<<'\n';
			while(sum>m){
				sum-=(a[j]-a[i]);
				i++;
				//cout<<i<<' ';
			}
		}
		//cout<<i<<' '<<j<<"  "<<sum<<' '<<j-i+1<<'\n';
	}
	cout<<mxlen;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
