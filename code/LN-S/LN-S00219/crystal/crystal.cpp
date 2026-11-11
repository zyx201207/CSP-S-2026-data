#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],flag=1,ans = 1;
bool cmp(long long x,long long y){
	return x>y;
}
void check(long long z){
	long long cnt=1,mm=m;
	for(int i=z+1;i<=n;i++){
		if(mm -(a[z]-a[i]) <0){
			ans = max(ans,cnt);
			return ;
		}
		else{
			mm-=a[z]-a[i];
			cnt++;
		}
	}
	ans = max(ans,cnt);
	//cout<<cnt<<" "<<ans<<"\n";
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];  
	sort(a+1,a+1+n,cmp);
	long long d = a[1]-a[2];
	long long ak = 0;
	for(int i=2;i<=n;i++)	ak+=a[1]-a[i];
	if(ak<=m){
		//cout<<"wcnm a!\n";
		cout<<n;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(a[i]-a[i+1]!=d){
			//cout<<"wcnm\n";
			for(int k=1;k<n;k++){
				check(k);
			}	
			cout<<ans;
			return 0;
		}
	}
	long long ac = a[1]-a[2],num=1,x=n;
	while(m>0&&x>0){
		if(m - num * ac >= 0){
			m -= num * ac;
			num++;
			x--;
		}
		else  break;
	}
	cout<<num;
	return 0;
}	
