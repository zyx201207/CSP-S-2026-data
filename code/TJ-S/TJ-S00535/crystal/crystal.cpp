#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long tmp[5005][5005];
long long sum[5005];
long long mis;
long long ans;//当前最优的ans 
long long disadd; 
long long cnt;
long long check(){
	long long res=a[2]-a[1];
	for(long long i=3;i<=n;i++){
		if(a[i]-a[i-1]!=res)return 0;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//1~9
	if(n<=5005){
		for(long long i=n;i>=1;i--){
			for(long long j=1;j<i;j++){
				tmp[i][j]=a[i]-a[j];
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<tmp[i][j]<<' ';
			}
			cout<<endl;
		}*/
		mis=55;
		ans=0; 
		for(long long i=1;i<=n;i++){
			for(long long j=i-1;j>=1;j--){
				sum[i]+=tmp[i][j];
				if(sum[i]<=m&&i-j>ans){
					ans=i-j;mis=sum[i];
				}
				else if(sum[i]<=m&&i-j==ans&&sum[i]<mis){
					ans=i-j;mis=sum[i];
				}
			}
		}
		cout<<ans+1;//最差情况下（不存在任何一个a[i]=a[j]且m=0)，ans=1,其余情况下，基准数也算可合成的，因此+1；
		return 0; 
	}
	//AB 
	else{//AB本质是一样的都是等差数列，区别在于A是固定差1，B不固定且大概率!=1; 
		//check作用：判断是否符合且分辨AB，返回值为等差值,不等差返回0; 
		disadd=check();
		if(disadd==0)return 0;//10~12&19,20
		cnt=0;
		if(disadd<=m&&disadd==1){//A 
			//cout<<"A";
			for(ans=1;;ans++){
				if(cnt+disadd*ans<=m){cnt+=disadd*ans;}
				else break;
			} 
		}
		else if(disadd<=m&&disadd>1){//B 
			//cout<<"B";
			for(ans=1;;ans++){
				if(cnt+disadd*ans<=m){cnt+=disadd*ans;}
				else break;
			} 
		}
		cout<<ans;
	} 
	return 0;
}
