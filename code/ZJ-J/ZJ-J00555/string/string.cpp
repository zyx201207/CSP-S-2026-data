#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[200005];
char b[200005];
long long sum1,sum2;
char c1,c2;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int i=1,j=n;
	while(i<j){
		if(sum1==0)sum1+=a[i],c1=b[i];
		if(sum2==0)sum2+=a[j],c2=b[j];
//		cout<<i<<j<<ans<<' '<<sum1<<' '<<sum2<<endl;
//		if(i+1==j){
//			if(sum1==sum2)break;
//		}
		if(sum1>sum2){
			if(c1!=c2)ans+=sum2;
			sum1=sum1-sum2;
			sum2=0;
			j--;
		}
		else if(sum2>sum1){
			if(c1!=c2)ans+=sum1;
			sum2=sum2-sum1;
			sum1=0;
			i++;
		}else{
			if(c1!=c2)ans+=sum1;
			sum1=sum2=0;
			i++;
			j--;
		}
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
//9:10 AC
/*
4
2 a
3 b
1 a
2 b
aabbbabb
*/
