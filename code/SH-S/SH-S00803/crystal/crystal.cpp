#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long cnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,d;//d为公差 
	cin>>n>>m;
	bool p=true,q=true;//p判断性质A，q判断性质B 
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]!=i)p=false;
	} 
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=d)q=false;
	}
	long long fans=0;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long ans=0;
//			memset(cnt,0,sizeof(cnt));
			long long cnt2=a[i],cnt4=m;
			long long cnt3=0;//小于cnt2的个数 
			for(int j=1;j<=i;j++){
				cnt[j]=cnt2-a[j];
				cnt3++;
			}
		//	cout<<i<<":";
			for(int j=1;j<=cnt3;j++){
				if(cnt4<cnt[j]){
					break;
				}else{
					cnt4-=cnt[j];
					ans++;
				}
			}
			fans=max(fans,ans);
		}
		cout<<fans;
		return 0;
	}
	else if(p==true){
		long long ans=0;
		long long cnt2=sqrt(2*m);
		if(cnt2*(cnt2+1)>2*m){
			cnt2--;
		}
		ans=cnt2+1;
		ans=min(ans,n);
		cout<<ans;
		return 0;
	}else if(q==true){
		long long ans=0;
		long long cnt2=sqrt(2*m/d);
		if(cnt2*(cnt2+1)*d>2*m){
			cnt2--;
		}
		ans=cnt2+1;
		ans=min(ans,n);
		cout<<ans;
		return 0;
	}
	else{
		long long cnt2[300],cnt3=m;
		memset(cnt2,0,sizeof(cnt2)); 
		for(int i=1;i<=n;i++){
			cnt2[a[i]+101]++;
		}
		for(int i=1;i<=201;i++){
			long long ans=0;
			cnt3=m;
			for(int j=i;j>=1;j--){
				if(cnt2[j]==0)continue;
				else if(cnt3>=(i-j)*cnt2[j]){
					ans+=cnt2[j];
					cnt3-=(i-j)*cnt2[j];
				}else{
					long long cnt4=(cnt3/(i-j));
					ans+=cnt4;
					break;
				}
			}
			fans=max(fans,ans);
		}
		cout<<fans;
	}
	return 0; 
} 
