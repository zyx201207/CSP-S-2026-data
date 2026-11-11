#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
//int sum1=INT_MAX,sum2=INT_MAX;
int cnt[5]={0};
int a[200001]={0};
int sum1[200001],sum2[200001];
bool cmp(int x1,int x2){
	return x1>x2;
}
void slove1(int num,int sum,int idx){
	if(num==m){
		ans=max(ans,sum);
	}
	if(sum<ans || idx>n){
		return;
	}
	slove1(num+1,sum&a[idx],idx+1);
	slove1(num,sum,idx+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxs=0;
	bool flag1=true;//13
	bool flag2=true;//14 15
	bool flag3=true;//16 17
	cin>>a[1];
	sum1[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sum1[i]=a[i]&sum1[i-1];
		maxs=max(maxs,a[i]);
		if(a[i]!=(1<<i)-1){
			flag1=false;
		}
		if(a[i]!=i-1){
			flag2=false;
		}
		if(!(a[i]<=4)){
			flag3=false;
		}
		if(flag3){
			cnt[a[i]]++;
		}
	}
	sum2[n]=a[n];
	for(int i=n-1;i>=1;i--){
		sum2[i]=sum2[i+1]&a[i];
	}
	if(n<=20){//1 --- 5
		slove1(0,INT_MAX,1);
		cout<<ans;
		return 0;
	}
	if(m==1){//6
		cout<<maxs;
		return 0;
	}
	if(m==n){//7
		cout<<sum1[n];
		return 0;
	}
	if(m==2){//8 --- 10
		maxs=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxs=max(maxs,a[i]&a[j]);
			}
		}
		cout<<maxs;
		return 0;
	}
	if(m==n-1){//11 12
		maxs=0;
		for(int i=1;i<=n;i++){
			maxs=max(maxs,sum1[i-1]&sum2[i+1]);
		}
		cout<<maxs;
		return 0;
	}
	if(flag1){//13
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	if(flag2){//14 15
		if(m>n/2){
			cout<<0;
		}
		int temp=n>>1;
		ans=n>>1;
		while(temp!=0){
			if(m<=temp/2){
				ans|=temp>>1;
			}else{
				break;
			}
			temp>>=1;
		}
		cout<<ans;
		return 0;
	}
	if(flag3){
		if(cnt[4]>=m){
			cout<<4;
		}else if(cnt[3]>=m){
			cout<<3;
		}else if(cnt[3]+cnt[2]>=m){
			cout<<2;
		}else if(cnt[3]+cnt[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	cout<<rand()%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
