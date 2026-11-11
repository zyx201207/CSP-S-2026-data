# include<bits/stdc++.h>
using namespace std;
struct str{
	long long cnt;
	char word;
}a[200010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	long long sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].word;
		sum+=a[i].cnt;
	}
	cout<<sum<<endl;
	sum/=2;
	long long l=1;
	long long r=n;
	for(long long i=1;i<=sum;i++){
		if(a[l].word!=a[r].word){
			ans++;
		}
		a[l].cnt--;
		a[r].cnt--;
		if(a[l].cnt==0){
			l++;
		}
		if(a[r].cnt==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
} 
