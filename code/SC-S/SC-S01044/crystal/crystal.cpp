#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
bool vis=0;
long long a[500005],cha[500005];
void s1(){
	long long len=a[2]-a[1];
	ans=1;
	for(long long i=1;i<n;i++){
		m-=len*((i+1)/2);
		if(m<0){
			break;
		}
		ans++;
	}
	cout << ans;
	return ;
}
void s2(){
	long long num,sum;
	for(int i=n;i>=1;i--){
		sum=0,num=m;
		for(int j=1;j<=i;j++){
			cha[j]=a[i]-a[j];
		}
		sort(cha+1,cha+1+i);
		for(int j=1;j<=n;j++){
			num-=cha[j];
			if(num<0){
				break;
			}
			sum++;
		}
		ans=max(sum,ans);
		if(i<=ans){
			break;
		}
	}
	cout << ans;
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]-a[i-1]!=a[i-1]-a[i-2] && i>=3){
			vis=1;
		}
	}
	sort(a+1,a+1+n);
	if(vis==0){
		s1();
	}else{
		s2();
	}
	return 0;
} 