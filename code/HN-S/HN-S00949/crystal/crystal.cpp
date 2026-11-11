#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],m,b[200010],ans;
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
		}
	}
	if(flag==0){
		cout<<min(n,m/(a[2]-a[1])+1);
		return 0;
	}
//	cout<<111<<endl;
//	if(a[n]<100000){
		for(long long i=1;i<=n;i++){
			b[a[i]+100000]++;
			a[i]+=100000;
		}
		for(long long i=1;i<=n;i++){
			long long now=0,ans1=0;
			for(long long j=a[i];j>=a[1];j--){
				if(b[j]==0)continue;
//				cout<<333<<' '<<a[i]-100000<<' '<<j-100000<<endl;
				if(now+(a[i]-j)*b[j]>=m){
					ans1+=(m-now)/(a[i]-j);
					ans=max(ans,ans1);
//					cout<<111<<' '<<i<<' '<<a[i]-100000<<' '<<ans1<<endl;
//					cout<<j-100000<<' '<<a[i]-100000<<endl;
//					cout<<3331<<endl;
					break; 
				}
				else{
					now+=(a[i]-j)*b[j];
					ans1+=b[j];
//					cout<<222<<' '<<i<<' '<<j-100000<<' '<<m-now<<' '<<ans1<<endl;
					ans=max(ans,ans1);
				}
			}
			ans=max(ans,ans1);
		}
//	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
